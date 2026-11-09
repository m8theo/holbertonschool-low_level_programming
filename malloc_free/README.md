# C - malloc, free

Ce projet contient mon projet **C - malloc, free**, réalisé dans le cadre du programme Holberton School.

Il couvre l'allocation dynamique de la mémoire en C, la différence entre l'allocation automatique sur la pile et l'allocation dynamique sur le tas, l'utilisation de `malloc` pour réserver de la mémoire et de `free` pour la libérer, la vérification systématique de la valeur de retour de `malloc`, ainsi que la détection des fuites de mémoire avec `valgrind`. Les seules fonctions de la bibliothèque standard autorisées sont `malloc` et `free`.

## Fichiers

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-create_array.c` : fonction `create_array` qui crée un tableau de `size` caractères, l'initialise avec le caractère `c` et renvoie un pointeur vers ce tableau, ou `NULL` si `size` vaut `0` ou si l'allocation échoue.
- `1-strdup.c` : fonction `_strdup` qui renvoie un pointeur vers une copie de la chaîne `str` dans un espace mémoire nouvellement alloué, ou `NULL` si `str` vaut `NULL` ou si la mémoire est insuffisante, comme `strdup`.
- `2-str_concat.c` : fonction `str_concat` qui renvoie un pointeur vers une nouvelle chaîne allouée contenant `s1` suivie de `s2` et terminée par `'\0'`, ou `NULL` en cas d'échec. Une chaîne `NULL` est traitée comme une chaîne vide.
- `3-alloc_grid.c` : fonction `alloc_grid` qui renvoie un pointeur vers un tableau d'entiers à deux dimensions de `width` colonnes et `height` lignes, dont chaque élément est initialisé à `0`. Elle renvoie `NULL` si `width` ou `height` vaut `0` ou est négatif, ou si une allocation échoue, après avoir libéré la mémoire déjà allouée.
- `4-free_grid.c` : fonction `free_grid` qui libère une grille à deux dimensions créée par `alloc_grid`, en libérant d'abord chacune des `height` lignes, puis le tableau de pointeurs.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Outil de vérification de la mémoire : `valgrind`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
