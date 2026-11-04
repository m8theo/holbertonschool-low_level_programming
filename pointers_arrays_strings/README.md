# C - Pointeurs, tableaux et chaînes de caractères

Ce projet contient mon projet **C - Pointeurs, tableaux et chaînes de caractères**, réalisé dans le cadre du programme Holberton School.

Il couvre les pointeurs et leur utilisation, les adresses mémoire, le déréférencement avec l'opérateur `*`, l'opérateur d'adresse `&`, les tableaux et leur parcours, les chaînes de caractères terminées par `'\0'`, ainsi que la différence entre un pointeur et un tableau. L'affichage se fait uniquement avec `_putchar`, sauf pour la fonction `print_array`, qui utilise `printf`.

## Fichiers

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-reset_to_98.c` : fonction `reset_to_98` qui reçoit un pointeur vers un `int` et met la valeur pointée à `98`.
- `1-swap.c` : fonction `swap_int` qui échange les valeurs de deux entiers à l'aide de leurs pointeurs.
- `2-strlen.c` : fonction `_strlen` qui renvoie la longueur d'une chaîne de caractères.
- `3-puts.c` : fonction `_puts` qui affiche une chaîne de caractères, suivie d'un retour à la ligne.
- `4-print_rev.c` : fonction `print_rev` qui affiche une chaîne de caractères à l'envers, suivie d'un retour à la ligne.
- `5-rev_string.c` : fonction `rev_string` qui inverse une chaîne de caractères directement en mémoire.
- `6-puts2.c` : fonction `puts2` qui affiche un caractère sur deux d'une chaîne, en commençant par le premier, suivi d'un retour à la ligne.
- `7-puts_half.c` : fonction `puts_half` qui affiche la seconde moitié d'une chaîne de caractères, suivie d'un retour à la ligne. Si la longueur est impaire, elle affiche les `(longueur - 1) / 2` derniers caractères.
- `8-print_array.c` : fonction `print_array` qui affiche les `n` premiers éléments d'un tableau d'entiers, séparés par `, `, suivis d'un retour à la ligne.
- `9-strcpy.c` : fonction `_strcpy` qui copie la chaîne pointée par `src`, y compris le `'\0'` final, dans le tampon pointé par `dest`, et renvoie `dest`.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `emacs`
