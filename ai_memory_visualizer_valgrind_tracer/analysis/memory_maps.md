# Memory Maps

## Conventions
- Pile (stack) : zone mémoire où chaque appel de fonction crée une frame contenant les variables locales, les paramètres et l’adresse de retour. 
- Tas (heap) : zone mémoire utilisée les allocations dynamiques avec `malloc()` qui restent valides jusqu'à leur libération explicite avec `free()`.
- Notation des adresses / des alias : une adresse mémoire est représentée en hexadécial et permet de localiser une donnée, deux pointeurs sont des alias lorsqu'il contiennet la même adresse et désignent la même zone mémoire.

## 1. stack_example.c

### Points clés d'exécution
| Étape | Ligne | Événement | Frames actives |
|-------|-------|-----------|----------------|
| E1 | 35 | Appel `walk_stack(0, 3)` | `main` > `walk_stack(0)` |
| E2  | 22  | Appel `dump_frame("enter", 0)` | `main` > `dump_frame(0)` > `dump_frame(0)` |
| E3  | 26  | Appel récursif `walk_stack(1)` | `main` > `walk_stack(0)` > `walk_stack(2)` |
| E4  | 26  | Appel récursif `walk_stack(2)` | `main` > `walk_stack(0)` > `walk_stack(1)` > `walk_stack(2)` |
| E5  | 26  | Appel récursif `walk_stack(3)` | `main` > `walk_stack(0)` > `walk_stack(1)` > `walk_stack(2)` > `walk_stack(3)` |
| E6  | 28  | Appel `dump_frame("exit", 3)` | Les 4 `walk_stack` + `dump_frame(3)` |
| E7  | 30  | Retour de `walk_stack(3)` | `main` + `walk_stack(0, 1, 2, 3)` |
| E8  | 28-30 | Retours successifs des niveaux 0, 1 et 2 | Les frames sont retirées progessivement |
| E9  | 36 | Retour de `main` | Fin du programme |


### Carte mémoire à l'étape E6
```text
           Adresses hautes
                  ↑
  ┌───────────────────────────┐
  │ main()                    │
  ├───────────────────────────┤
  │ walk_stack(0, 3)          │
  │ marker = 0                │
  │ &marker = A               │
  ├───────────────────────────┤
  │ walk_stack(1, 3)          │
  │ marker = 10               │
  │ &marker = A - 48          │
  ├───────────────────────────┤
  │ walk_stack(2, 3)          │
  │ marker = 20               │
  │ &marker = A - 96          │
  ├───────────────────────────┤
  │ walk_stack(3, 3)          │
  │ marker = 30               │
  │ &marker = A - 144         │
  └───────────────────────────┘
                  ↓
           Adresses basses
```

Ici, `A` représente l'adresse observée de `marker` au niveau 0. Les écarts indiqués supposent une différence de 48 octets entre deux niveaux successifs, telle que rapportée dans l'exercice. Les quatre frames de `walk_stack` sont actives en même temps.

Observation importante : lorsque `walk_stack(1)` commence, `dump_frame("enter", 0)` est déjà retournée : sa frame n'est plus active et son espace est réutilisable. Les 48 octets mesurent l'écart entre les emplacements de `marker` de deux appels successifs de `walk_stack`, et non l'espace occupé par la frame de `dump_frame`.

### Durée de vie des variables
| Variable | Frame | Début de vie | Fin de vie |
|----------|-------|--------------|------------|
| `marker = 0` | `walk_stack(0)` | E1 |	Retour de `walk_stack(0)` |
| `marker = 10` | `walk_stack(1)` |	E3 | Retour de `walk_stack(1)` |
| `marker = 20` | `walk_stack(2)` | E4 | Retour de `walk_stack(2)` |
| `marker = 30` | `walk_stack(3)` |	E5 | E7 |
| `local_int` |	`dump_frame` | Entrée dans `dump_frame` | Retour de `dump_frame` |
| `local_buf[16]` |	`dump_frame` | Entrée dans `dump_frame`	| Retour de `dump_frame` |
| `p_local` | `dump_frame` | Entrée dans `dump_frame` | Retour de `dump_frame` |

## 2. aliasing_example.c

### Carte mémoire avant free(a)

```text
       STACK                        HEAP
 ┌──────────────────┐          ┌─────────────────────┐
 │ main()           │          │ Bloc à l'adresse H  │
 │                  │          │                     │
 │ a = H ───────────┼─────────►│ [0] = 0             │
 │ b = H ───────────┼─────────►│ [1] = 11            │
 │ n = 5            │          │ [2] = 22            │
 └──────────────────┘          │ [3] = 33            │
                               │ [4] = 44            │
                               └─────────────────────┘
```

À la ligne 30, `make_numbers(5)` alloue un tableau de cinq `int`. À la ligne 34, `b = a` copie une adresse : **aucune seconde allocation n'est créée**. `a` et `b` sont deux alias du même bloc (`5 × sizeof(int)`, soit généralement 20 octets).


### Carte mémoire après free(a)

```text
       STACK                        HEAP
 ┌──────────────────┐          ┌─────────────────────┐
 │ main()           │          │ Ancien bloc H       │
 │                  │          │                     │
 │ a = H  ─ ─ ─ ─ ─ ┼ ─ ─ ─ ─ ►│ LIBÉRÉ              │
 │ b = H  ─ ─ ─ ─ ─ ┼ ─ ─ ─ ─ ►│ (accès interdits)   │
 │ n = 5            │          │                     │
 └──────────────────┘          └─────────────────────┘

   a et b sont des pointeurs pendants (dangling pointers).
```

| Ligne | Instruction | Conséquence |
|---|---|---|
| 30 | `a = make_numbers(n)` | Allocation et initialisation des cinq entiers |
| 34 | `b = a` | `b` devient un alias de `a` |
| 38 | `free(a)` | Le bloc est libéré ; aucun des deux pointeurs ne permet plus d'y accéder |
| 42 | `b[2]` | Lecture après libération (use-after-free) : comportement indéfini |
| 44 | `b[3] = 1234` | Écriture après libération : comportement indéfini |
| 45 | `b[3]` | Nouvelle lecture après libération : comportement indéfini |

### Propriété (ownership) et alias
- Qui possède le bloc ? Dans ce programme, `main` reçoit le bloc alloué par `make_numbers`, via `a`, et en assume la gestion.
- Qui doit le libérer ? `main`, avec un unique `free(a)` (un `free(b)` avant toute libération aurait également libéré le même bloc, mais il ne faut pas le libérer deux fois).
- Quel est le rôle de `b` ?** C'est un alias : il ne possède pas un deuxième bloc.
- À partir de quand `b` est-il invalide ?** Dès l'appel à `free(a)` en ligne 38 : les accès ultérieurs par `b` sont invalides.

Bilan : deux pointeurs peuvent désigner le même bloc. Libérer ce bloc invalide tous les accès passant par ses alias. Valgrind peut signaler les lectures et écritures invalides des lignes 42, 44 et 45.

| Question |  Réponse  |
|----------|-----------|
| Qui possède le bloc ? | `a` reçoit le pointeur de l'allocation et en assure initialement la gestion. |
| Quel est le rôle de `b` ?	| `b` est un alias de a, sans nouvelle allocation. |
| Qui doit libérer le bloc ? | Le programme doit appeler free une seule fois, ici avec `free(a)`. |
| Quand b devient-il invalide ? | Dès l'exécution de `free(a)` à la ligne 38. |
| Que provoque son utilisation ? | Un comportement indéfini (use-after-free). |

## 3. heap_example.c (optionnel)

## Utilisation de l'IA
| # | Prompt (résumé) | Affirmation de l'IA | Verdict | Correction et justification |
|---|---|---|---|---|
| 1 | Définir la pile | Une frame contient variables locales, paramètres et informations de retour. | Incomplet | La disposition exacte dépend du compilateur et de l'architecture ; certaines valeurs peuvent résider dans des registres. |
| 2 | Déterminer le sens de croissance | La pile croît vers les adresses basses. | Correct pour l'observation rapportée | Sur la plateforme indiquée, les adresses de `marker` diminuent pendant la récursion ; cette propriété ne se généralise pas à toutes les plateformes. |
| 3 | Interpréter les 48 octets | Ils représentent la place d'une frame. | Trompeur | Ils mesurent exactement la différence entre deux adresses de `marker` successives ; cela ne prouve pas, à lui seul, la taille totale de la frame. |
| 4 | Durée de vie de `dump_frame` | Sa frame disparaît avant l'appel récursif suivant. | Correct | `dump_frame("enter", 0)` est retournée avant le début de `walk_stack(1)` ; l'espace peut être réutilisé. |
| 5 | Comprendre `b = a` | `b` pointe vers le même tableau que `a`. | Correct | L'affectation copie l'adresse et n'alloue aucun bloc supplémentaire. |
| 6 | Effet de `free(a)` | `b` devient un pointeur pendant. | Correct | Le tableau a été libéré ; les accès par `b` des lignes 42 à 45 ont un comportement indéfini. |
| 7 | Étudier la fuite du tas | Le nom d'Alice fuit sur six octets. | *orrect pour le chemin normal | `person_free_partial` appelle `free(p)` sans `free(p->name)` ; la chaîne `"Alice\0"` occupe six octets. |


## Conclusion

La pile gère automatiquement les durées de vie liées aux appels de fonctions, tandis que le tas demande des libérations explicites. Les alias donnent plusieurs moyens d'accéder à un même bloc, mais n'en changent pas la durée de vie : une fois le bloc libéré, aucun alias ne peut encore être utilisé pour y accéder.