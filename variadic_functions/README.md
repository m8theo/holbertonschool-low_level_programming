# C - Fonctions variadiques

Ce projet contient mon projet **C - Fonctions variadiques**, réalisé dans le cadre du programme Holberton School.

Il couvre les fonctions variadiques en C, c'est-à-dire les fonctions qui acceptent un nombre variable d'arguments, ainsi que l'utilisation du type `va_list` et des macros `va_start`, `va_arg` et `va_end` de l'en-tête `<stdarg.h>` pour parcourir ces arguments. Il aborde aussi le qualificateur de type `const`, qui empêche la modification d'une variable ou de la valeur pointée. Les seules fonctions de la bibliothèque standard autorisées sont `malloc`, `free` et `exit`, sauf pour les fonctions `print_numbers`, `print_strings` et `print_all`, qui utilisent `printf`.

## Fichiers

- `variadic_functions.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-sum_them_all.c` : fonction `sum_them_all` qui renvoie la somme de tous ses paramètres, dont le nombre est donné par `n`. Elle renvoie `0` si `n` vaut `0`.
- `1-print_numbers.c` : fonction `print_numbers` qui affiche les `n` entiers reçus en paramètres, séparés par la chaîne `separator`, suivis d'un retour à la ligne. Le séparateur n'est pas affiché s'il vaut `NULL`.
- `2-print_strings.c` : fonction `print_strings` qui affiche les `n` chaînes de caractères reçues en paramètres, séparées par la chaîne `separator`, suivies d'un retour à la ligne. Le séparateur n'est pas affiché s'il vaut `NULL`, et une chaîne `NULL` est affichée sous la forme `(nil)`.
- `3-print_all.c` : fonction `print_all` qui affiche des arguments de n'importe quel type listé dans la chaîne `format` (`c` pour un `char`, `i` pour un entier, `f` pour un `float` et `s` pour une chaîne de caractères), séparés par `, ` et suivis d'un retour à la ligne. Tout autre caractère de `format` est ignoré, et une chaîne `NULL` est affichée sous la forme `(nil)`. Elle est écrite sans `for`, `goto`, `else`, `do ... while` ni opérateur ternaire, avec au plus 2 boucles `while`, 2 instructions `if` et 9 variables.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
