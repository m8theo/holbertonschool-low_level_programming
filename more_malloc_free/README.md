# C - Plus de malloc, free

Ce projet contient mon projet **C - Plus de malloc, free**, réalisé dans le cadre du programme Holberton School.

Il approfondit l'allocation dynamique de la mémoire en C avec `malloc` et `free`, et couvre l'utilisation de la fonction `exit` pour terminer un programme avec un code de retour donné, ainsi que le fonctionnement des fonctions `calloc` et `realloc` de la bibliothèque standard. La fonction `calloc` est réécrite à l'aide de `malloc`. Les seules fonctions de la bibliothèque standard autorisées sont `malloc`, `free` et `exit`.

## Fichiers

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-malloc_checked.c` : fonction `malloc_checked` qui alloue `b` octets avec `malloc` et renvoie un pointeur vers la mémoire allouée. Si `malloc` échoue, elle termine normalement le processus avec le code de retour `98`.
- `1-string_nconcat.c` : fonction `string_nconcat` qui renvoie un pointeur vers une nouvelle chaîne allouée contenant `s1` suivie des `n` premiers octets de `s2` et terminée par `'\0'`, ou `NULL` en cas d'échec. Si `n` est supérieur ou égal à la longueur de `s2`, la chaîne `s2` entière est utilisée. Une chaîne `NULL` est traitée comme une chaîne vide.
- `2-calloc.c` : fonction `_calloc` qui alloue avec `malloc` la mémoire d'un tableau de `nmemb` éléments de `size` octets chacun, met cette mémoire à zéro et renvoie un pointeur vers celle-ci. Elle renvoie `NULL` si `nmemb` ou `size` vaut `0`, ou si `malloc` échoue.
- `3-array_range.c` : fonction `array_range` qui crée un tableau d'entiers contenant toutes les valeurs de `min` à `max` inclus, dans l'ordre croissant, et renvoie un pointeur vers ce tableau. Elle renvoie `NULL` si `min` est supérieur à `max` ou si `malloc` échoue.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Outil de vérification de la mémoire : `valgrind`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
