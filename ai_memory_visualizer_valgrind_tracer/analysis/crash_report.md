# Crash Report
Environnement : conteneur Docker Ubuntu 24.04 (arm64 / aarch64), GCC 13, Valgrind 3.22.0, gdb.

## 1. Description du plantage

- **Commande** : `./crash_example; echo "exit status: $?"`
- **Symptôme** : `Segmentation fault`, exit status **[139]** = 128 + 11 (SIGSEGV).
  Un processus tué par un signal N renvoie au shell 128 + N.
- **Ligne fautive** : `crash_example.c:32`, `nums[0] = 42;`
- **Preuves** :
  - Valgrind : `Invalid write of size 4 at main (crash_example.c:32)` / `Address 0x0 is not stack'd, malloc'd or (recently) free'd`
  - gdb : `Program received signal SIGSEGV` à la ligne 32, `print nums` → `$1 = (int *) 0x0`

## 2. Chaîne causale

1. **Ligne [..]** : `main` appelle `allocate_numbers(n)` avec `n = 0`.
2. **Ligne [..] (`allocate_numbers`)** : [à compléter d'après le code : condition qui fait renvoyer `NULL`,
   et préciser si `malloc` est appelé ou non].
3. **Ligne 30** : `nums` reçoit `NULL`. Aucune vérification n'est faite dans `main` avant l'utilisation :
   c'est ici que se trouve la **cause racine** (le contrat de `allocate_numbers` est « peut renvoyer NULL »,
   l'appelant ne le respecte pas).
4. **Ligne 32** : `nums[0] = 42;` équivaut à `*(nums + 0) = 42;`, c'est-à-dire `*(int *)0 = 42;`
   → écriture de 4 octets (`sizeof(int)`) à l'adresse `0x0`.
5. **Conséquence** : le processeur ne trouve aucune page mappée à l'adresse 0, le noyau envoie SIGSEGV,
   action par défaut = terminaison du processus.
6. **Lignes 34 et 36** ne sont jamais exécutées. Même si elles l'étaient, `free(NULL)` est défini par la norme C
   comme une opération sans effet : il ne planterait pas.

## 3. Pourquoi l'accès est invalide

- **Où vit `nums` ?** Sur la **pile**, dans la frame de `main` (gdb : `Locals at 0xfffffffff470`, zone haute de la pile).
  La variable elle-même est parfaitement valide.
- **Où pointe-t-elle ?** Nulle part : sa valeur est `0x0`. Cette adresse n'appartient **ni à la pile, ni au tas**,
  ce que Valgrind confirme : `not stack'd, malloc'd or (recently) free'd`. Aucun objet n'existe à cette adresse.
- **Pourquoi le système intervient** : Linux ne mappe jamais les pages les plus basses de l'espace d'adressage
  (paramètre `vm.mmap_min_addr`). Toute lecture ou écriture vers l'adresse 0 déclenche une faute de page que le noyau
  ne peut pas résoudre → `Access not within mapped region at address 0x0` → SIGSEGV.
- **Pourquoi c'est déterministe** : l'adresse écrite est toujours exactement 0 (pas une valeur résiduelle ou aléatoire),
  et la page 0 n'est jamais mappée, quel que soit l'ASLR. Le programme plante donc à chaque exécution, au même endroit.
  À l'inverse, le use-after-free de `aliasing_example` (tâche 1) ne plantait pas, car l'adresse visée restait dans une
  zone mappée.

### Observation annexe : `still reachable: 1,024 bytes in 1 blocks`
Ce bloc est le tampon de `stdout` alloué par `printf`. Il n'est pas libéré car le processus est tué par le signal
sans passer par `exit()` (pas de nettoyage de la libc). Ce n'est **pas** une fuite du programme.
Conséquence pratique : si la sortie avait été redirigée vers un fichier (tampon complet au lieu de ligne par ligne),
les derniers `printf` non vidés auraient été perdus au moment du plantage.

## 4. Catégorie de comportement indéfini

- **Déréférencement d'un pointeur nul** (null pointer dereference). La norme C (C11 §6.5.3.2) rend indéfini
  l'opérateur `*` appliqué à un pointeur invalide, dont le pointeur nul.
- Ce n'est **pas** un dépassement de tableau (aucun tableau n'existe), ni un use-after-free (rien n'a été libéré),
  ni un débordement de pile.
- **Référence CERT C** : EXP34-C, *Do not dereference null pointers*.
- Sur Linux, ce comportement indéfini se manifeste par une SIGSEGV. Mais la norme ne garantit rien :
  un compilateur qui optimise peut supposer que `nums` n'est jamais nul et transformer le code de façon inattendue.

## 5. Critique des suggestions de l'IA

| Suggestion de l'IA | Verdict | Justification |
|---|---|---|
| Message de Valgrind : « If you believe this happened as a result of a stack overflow… increase --main-stacksize » | **Fausse piste** | Message générique affiché pour toute SIGSEGV. L'adresse fautive est 0x0, pas une adresse proche de la pile ; il n'y a aucune récursion. |
| Valgrind : « Rerun with --leak-check=full to see details of leaked memory » | **Hors sujet** | Le seul bloc restant est le tampon stdout *still reachable*, conséquence de la terminaison par signal, pas une fuite. |
| [Citation exacte de l'IA que tu interroges] | … | … |
| [ex. « La cause est malloc(0) »] | [à vérifier dans le code] | [malloc est-il appelé quand n = 0 ?] |
| [ex. « Corriger en mettant n = 1 »] | **Masque le symptôme** | Le code planterait toujours dès qu'une allocation échoue ; la cause racine est l'absence de vérification de NULL. |

## 6. (Facultatif) Correction suggérée

> Correction proposée, **non appliquée au code** :
> vérifier la valeur de retour avant tout déréférencement.
> ```c
> nums = allocate_numbers(n);
> if (nums == NULL)
> {
>     fprintf(stderr, "allocate_numbers failed (n = %d)\n", n);
>     return 1;
> }
> ```
> Cette correction traite la cause racine : elle protège aussi contre un échec réel de `malloc`, pas seulement contre `n = 0`.