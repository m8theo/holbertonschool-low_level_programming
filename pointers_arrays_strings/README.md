# C - Pointeurs, tableaux et chaînes de caractères

Ce dossier contient mes projets **C - Pointeurs, tableaux et chaînes de caractères**, **C - Autres pointeurs, tableaux et chaînes de caractères** et **C - Encore plus de pointeurs, tableaux et chaînes de caractères**, réalisés dans le cadre du programme Holberton School.

Ils couvrent les pointeurs et leur utilisation, les adresses mémoire, le déréférencement avec l'opérateur `*`, l'opérateur d'adresse `&`, les tableaux et leur parcours, les chaînes de caractères terminées par `'\0'`, ainsi que la différence entre un pointeur et un tableau. Le second projet approfondit ces notions en réécrivant des fonctions de la bibliothèque standard (`strcat`, `strncat`, `strncpy`, `strcmp`) et en modifiant directement en mémoire le contenu de tableaux et de chaînes. Le troisième projet introduit les pointeurs de pointeurs et les tableaux multidimensionnels, et réécrit des fonctions de manipulation de la mémoire et de recherche dans les chaînes (`memset`, `memcpy`, `strchr`, `strspn`, `strpbrk`, `strstr`). L'affichage se fait uniquement avec `_putchar`, sauf pour les fonctions `print_array` et `print_diagsums`, qui utilisent `printf`.

## Fichiers

### `pointers_arrays_strings_1` : C - Pointeurs, tableaux et chaînes de caractères

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
- `100-atoi.c` : fonction `_atoi` qui convertit une chaîne de caractères en entier, en tenant compte de tous les signes `-` et `+` qui précèdent le nombre.

### `pointers_arrays_strings_2` : C - Autres pointeurs, tableaux et chaînes de caractères

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-strcat.c` : fonction `_strcat` qui ajoute la chaîne `src` à la fin de la chaîne `dest`, en écrasant le `'\0'` final de `dest`, et renvoie `dest`.
- `1-strncat.c` : fonction `_strncat` qui ajoute au plus `n` octets de la chaîne `src` à la fin de la chaîne `dest`, puis un `'\0'` final, et renvoie `dest`.
- `2-strncpy.c` : fonction `_strncpy` qui copie au plus `n` octets de la chaîne `src` dans `dest`, complète avec des `'\0'` si `src` est plus courte que `n`, et renvoie `dest`, comme `strncpy`.
- `3-strcmp.c` : fonction `_strcmp` qui compare deux chaînes de caractères et renvoie la différence entre les deux premiers caractères qui diffèrent, ou `0` si elles sont identiques.
- `4-rev_array.c` : fonction `reverse_array` qui inverse le contenu d'un tableau de `n` entiers directement en mémoire.
- `5-string_toupper.c` : fonction `string_toupper` qui transforme toutes les lettres minuscules d'une chaîne en majuscules et renvoie la chaîne.
- `6-cap_string.c` : fonction `cap_string` qui met en majuscule la première lettre de chaque mot d'une chaîne. Les séparateurs de mots sont l'espace, la tabulation, le retour à la ligne et les caractères `,` `;` `.` `!` `?` `"` `(` `)` `{` `}`.
- `7-leet.c` : fonction `leet` qui encode une chaîne en 1337 en remplaçant `a` et `A` par `4`, `e` et `E` par `3`, `o` et `O` par `0`, `t` et `T` par `7`, `l` et `L` par `1`, avec un seul `if` et deux boucles.

### `pointers_arrays_strings_3` : C - Encore plus de pointeurs, tableaux et chaînes de caractères

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-memset.c` : fonction `_memset` qui remplit les `n` premiers octets de la zone mémoire pointée par `s` avec l'octet constant `b`, et renvoie `s`, comme `memset`.
- `1-memcpy.c` : fonction `_memcpy` qui copie `n` octets de la zone mémoire `src` vers la zone mémoire `dest`, et renvoie `dest`, comme `memcpy`.
- `2-strchr.c` : fonction `_strchr` qui renvoie un pointeur vers la première occurrence du caractère `c` dans la chaîne `s`, ou `NULL` s'il n'est pas trouvé, comme `strchr`.
- `3-strspn.c` : fonction `_strspn` qui renvoie le nombre d'octets du segment initial de `s` composé uniquement d'octets présents dans `accept`, comme `strspn`.
- `4-strpbrk.c` : fonction `_strpbrk` qui renvoie un pointeur vers le premier octet de `s` présent dans `accept`, ou `NULL` si aucun ne correspond, comme `strpbrk`.
- `5-strstr.c` : fonction `_strstr` qui renvoie un pointeur vers le début de la première occurrence de la sous-chaîne `needle` dans `haystack`, sans comparer les `'\0'` finaux, ou `NULL` si elle n'est pas trouvée, comme `strstr`.
- `7-print_chessboard.c` : fonction `print_chessboard` qui reçoit un tableau à deux dimensions `char (*a)[8]` et affiche l'échiquier, une ligne de 8 caractères par rangée.
- `8-print_diagsums.c` : fonction `print_diagsums` qui affiche la somme de la diagonale principale puis celle de l'antidiagonale d'une matrice carrée d'entiers de taille `size`, passée sous forme de `int *`, séparées par `, ` et suivies d'un retour à la ligne.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
