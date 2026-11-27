# Valgrind Analysis

Environnement : conteneur Docker Ubuntu 24.04 (arm64), GCC 13, Valgrind 3.22.0.

## Commandes utilisées

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=../heap.log ./heap_example
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=../alias.log ./aliasing_example
valgrind --log-file=../stack.log ./stack_example
```

| Option | Rôle |
|---|---|
| `--leak-check=full` | Détaille chaque fuite avec la pile d'appels de son allocation (sinon : résumé seulement). |
| `--show-leak-kinds=all` | Affiche les 4 catégories (definitely, indirectly, possibly, still reachable) ; par défaut "still reachable" est masqué. |
| `--track-origins=yes` | Pour une valeur non initialisée, indique où elle a été créée. **Aucune erreur de ce type n'apparaît dans mes sorties** : l'option n'a donc rien produit ici. |
| `--log-file` | Sépare la sortie Valgrind de la sortie du programme pour pouvoir l'analyser. |

### Remarque sur la compilation
Avec GCC 13, le Makefile échoue sur `aliasing_example.c` : `-Wall` active `-Wuse-after-free` et `-Werror` le transforme en erreur
(lignes 40, 42, 44, 45). J'ai compilé ce fichier avec `-Wno-error=use-after-free` pour garder l'avertissement sans bloquer :

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -Wno-error=use-after-free -o aliasing_example aliasing_example.c
```

Le compilateur détecte donc **statiquement** le bug que Valgrind détecte **à l'exécution**. Mais les deux ne signalent pas les mêmes lignes (voir 2.4).

---

## 1. heap_example.c

### Résumé

```
in use at exit: 6 bytes in 1 blocks
total heap usage: 5 allocs, 4 frees, 1,066 bytes allocated
definitely lost: 6 bytes in 1 blocks
indirectly lost: 0 / possibly lost: 0 / still reachable: 0
```

### Vérification du compte (à partir du code)

| Allocation | Ligne | Taille | Libérée ? |
|---|---|---|---|
| `Person` d'Alice | 14 (appel ligne 51) | `sizeof(Person)` = 16 (8 pointeur + 4 int + 4 padding) | oui, ligne 41 via `person_free_partial` (ligne 69) |
| `name` d'Alice `"Alice"` | 21 (appel ligne 51) | 5 + 1 (`'\0'`) = **6** | **non** |
| `Person` de Bob | 14 (appel ligne 52) | 16 | oui, ligne 67 |
| `name` de Bob `"Bob"` | 21 (appel ligne 52) | 3 + 1 = 4 | oui, ligne 66 |
| tampon de `stdout` (alloué par `printf`) | interne à la libc | 1 024 | oui (à la fin du programme) |

Total : 5 allocs, 4 frees, 16 + 6 + 16 + 4 + 1 024 = **1 066 octets** : identique à Valgrind.
Différence : 1 bloc de 6 octets : identique à `definitely lost: 6 bytes in 1 blocks`.

Le tampon de `printf` explique pourquoi on voit 5 allocs alors que le code ne contient que 4 `malloc` exécutés.
Il n'est pas une fuite : la libc le libère.

### Problème 1 : fuite par perte de propriété
- **Type d'erreur** : memory leak, *definitely lost* (loss record 1 of 1)
- **Objet mémoire** : la chaîne `"Alice"`, bloc de 6 octets sur le tas
- **Allocation** : `heap_example.c:21` (`p->name = malloc(len + 1)` dans `person_new`), appelé depuis `main` ligne 51
- **Perte de la dernière référence** : ligne 41, `free(p)` dans `person_free_partial`, appelé ligne 69
- **Explication (propriété)** :
  `person_new` crée deux blocs. Le bloc `Person` **possède** le bloc `name` : la seule référence à `name` est le champ `p->name`,
  stocké *à l'intérieur* du bloc `Person`. `person_free_partial` libère le bloc `Person` sans libérer `p->name` d'abord.
  À cet instant, la seule copie de l'adresse `0x4a7e4d0` (adresse observée de `alice->name`) se trouve dans une zone libérée.
  Plus aucun pointeur valide ne mène au bloc : personne ne peut plus le libérer.
- **Pourquoi "definitely" et pas "indirectly"** :
  *indirectly lost* signifie « seulement atteignable via un autre bloc *lui-même perdu mais encore alloué* ».
  Ici le bloc `Person` a été **libéré**, pas perdu : Valgrind ne parcourt pas les blocs libérés pour chercher des pointeurs.
  Le bloc `name` n'a donc aucun pointeur, ni direct ni indirect, d'où *definitely lost*.
  (Si `free(p)` n'avait jamais été appelé, on aurait eu `Person` = definitely lost et `name` = indirectly lost.)
- **Contre-exemple dans le même programme** : Bob ne fuit pas, car `main` libère dans le bon ordre (lignes 66-67) :
  d'abord `bob->name` (le bloc possédé), puis `bob` (le propriétaire). L'ordre inverse serait un use-after-free,
  car `bob->name` lirait un champ du bloc déjà libéré.
- **Lien avec memory_maps.md** : section heap_example, schéma à deux niveaux `Person → name`.

---

## 2. aliasing_example.c

### Contexte mémoire
- Ligne 12 : `make_numbers` alloue un bloc de **20 octets** = `5 * sizeof(int)` sur le tas.
  `arr` (variable locale de `make_numbers`) meurt au `return` ligne 19, mais le bloc survit : son adresse est copiée dans `a` (ligne 30).
- Ligne 34 : `b = a` : **deux pointeurs, un seul bloc** (aliasing). `a` et `b` vivent dans la frame de `main`.
- Ligne 38 : `free(a)` termine la durée de vie **du bloc**. Ni `a` ni `b` ne sont modifiés :
  ils contiennent toujours l'adresse `0x4a7e480`, mais elle ne désigne plus un objet valide (dangling pointers).

### Problème 1 : use-after-free en lecture (ligne 42)
- **Type** : `Invalid read of size 4`
- **Taille** : 4 = `sizeof(int)`, un seul élément du tableau est lu
- **Adresse** : `0x4a7e488` = début du bloc `0x4a7e480` + **8** = `2 * sizeof(int)` → c'est exactement `b[2]`
- **Bloc** : alloué `aliasing_example.c:12` (via l'appel ligne 30), libéré ligne 38
- **Accès fautif** : ligne 42, `printf(..., b[2])`
- **Explication** : `b` est un alias de `a`. Libérer via `a` libère le bloc partagé ; lire via `b` lit donc une zone libérée.

### Problème 2 : use-after-free en écriture (ligne 44)
- **Type** : `Invalid write of size 4`
- **Adresse** : `0x4a7e48c` = début + **12** = `3 * sizeof(int)` → `b[3]`
- **Bloc** : alloué ligne 12, libéré ligne 38
- **Explication** : écriture de `1234` dans une zone rendue à l'allocateur. C'est le cas le plus dangereux :
  dans un vrai programme, cette zone peut avoir été réattribuée à une autre allocation, qui serait alors corrompue silencieusement.

### Problème 3 : use-after-free en lecture (ligne 45)
- **Type** : `Invalid read of size 4`, même adresse `0x4a7e48c` (`b[3]`)
- **Explication** : relecture de la valeur qu'on vient d'écrire illégalement. Le fait qu'elle affiche `1234` ne la rend pas valide.

### 2.4 Ce que Valgrind ne signale pas (et ce que GCC signale)
- **Ligne 36** : `a[2]` et `b[2]` sont lus *avant* le `free` → accès valides, aucune erreur.
- **Ligne 40** : `printf("%p", (void *)b)`. Valgrind ne signale rien : on lit la **valeur du pointeur** `b`, stockée dans
  la frame de `main` (pile), pas le contenu du bloc. Memcheck ne surveille que les accès au bloc.
  GCC, lui, signale cette ligne : pour la norme C, la valeur d'un pointeur devient *indéterminée* après `free`,
  donc même l'utiliser sans déréférencement est techniquement un comportement indéfini.
  → Valgrind vérifie les **accès mémoire réels**, GCC vérifie les **règles du langage**. Les deux diagnostics sont complémentaires.
- **Aucune fuite** : `2 allocs, 2 frees, 1,044 bytes` = bloc de 20 octets + tampon `stdout` de 1 024 octets, tous libérés.

### Comportement indéfini vs symptôme
Le programme se termine normalement et affiche : [COLLER ICI la sortie standard : valeurs de b[2] et b[3]].
Cela ne prouve **pas** que le code est correct : un use-after-free est un comportement indéfini, pas un plantage garanti.
Ici, le bloc libéré n'a été réutilisé par aucune autre allocation, donc les anciennes valeurs étaient encore lisibles.
Sous Valgrind, les blocs libérés sont en plus mis en quarantaine (non réutilisés immédiatement), ce qui rend ce cas encore plus probable.

---

## 3. stack_example.c (témoin)

```
total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
ERROR SUMMARY: 0 errors
```

- Le seul alloc est le tampon `stdout` de `printf` : le programme lui-même n'utilise que la pile.
- 0 erreur attendue : les variables locales (`local_int`, `local_buf`, `marker`, `p_local`) sont créées et détruites
  automatiquement avec leur frame. `p_local` ne survit jamais à `local_int` puisqu'ils sont dans la même frame.
- Limite : Memcheck ne détecte pas les débordements de tableaux **sur la pile** (il ne connaît pas les limites de `local_buf`).
  « 0 erreur » n'est donc pas une preuve absolue d'absence de bug sur la pile.

---

## Utilisation de l'IA

Assistant utilisé : Claude. Ses explications ont été traitées comme des hypothèses, puis vérifiées contre les logs et le code.

| # | Ce que l'IA a affirmé | Vérification | Verdict | Correction |
|---|---|---|---|---|
| 1 | « Quatre erreurs Valgrind sont attendues » sur `aliasing_example` (lignes 40 à 45) | `alias.log` : `3 errors from 3 contexts` (lignes 42, 44, 45) | **Faux** | La ligne 40 ne lit que la valeur du pointeur, pas le bloc : Memcheck ne la signale pas. L'IA a confondu le diagnostic de GCC (qui signale 4 lignes) avec celui de Valgrind. |
| 2 | Le bloc a été alloué via `make_numbers` « appelé ligne 31 » | `alias.log` : `by 0x10891F: main (aliasing_example.c:30)` ; ligne 30 du code = `a = make_numbers(n);` | **Faux** | L'appel est ligne 30. Exemple typique de mauvaise attribution de ligne : il faut toujours relire la pile d'appels réelle. |
| 3 | Le nom d'Alice est *definitely lost* et non *indirectly lost* | `heap.log` : `definitely lost: 6 bytes`, `indirectly lost: 0` | Correct | Confirmé : le bloc `Person` qui contenait le pointeur a été libéré, donc pas parcouru. |
| 4 | 5 allocs dont 1 pour le tampon `printf`, 1 066 octets au total | `heap.log` + calcul à partir du code | Correct | Recalculé à la main (tableau section 1). |