# C - Pointeurs de fonctions

Ce projet contient mon projet **C - Pointeurs de fonctions**, réalisé dans le cadre du programme Holberton School.

Il couvre les pointeurs de fonctions en C : ce qu'ils sont, ce qu'ils contiennent exactement (l'adresse du code d'une fonction), vers quelle zone de la mémoire virtuelle ils pointent, ainsi que leur utilisation pour passer une fonction en paramètre à une autre fonction. Il aborde aussi l'utilisation d'un tableau de structures associant un opérateur à un pointeur de fonction pour réaliser une calculatrice simple. Les seules fonctions de la bibliothèque standard autorisées sont `malloc`, `free` et `exit`, sauf pour la calculatrice, qui peut utiliser toute la bibliothèque standard.

## Fichiers

- `function_pointers.h` : fichier d'en-tête contenant les prototypes des fonctions `print_name`, `array_iterator` et `int_index`, ainsi que celui de `_putchar`.
- `0-print_name.c` : fonction `print_name` qui affiche un nom à l'aide de la fonction pointée par `f`, reçue en paramètre. Elle ne fait rien si `name` ou `f` vaut `NULL`.
- `1-array_iterator.c` : fonction `array_iterator` qui exécute la fonction pointée par `action` sur chacun des `size` éléments d'un tableau d'entiers. Elle ne fait rien si `array` ou `action` vaut `NULL`.
- `2-int_index.c` : fonction `int_index` qui recherche un entier dans un tableau et renvoie l'indice du premier élément pour lequel la fonction de comparaison `cmp` ne renvoie pas `0`. Elle renvoie `-1` si aucun élément ne correspond, si `size` est inférieur ou égal à `0`, ou si `array` ou `cmp` vaut `NULL`.
- `3-calc.h` : fichier d'en-tête de la calculatrice contenant la structure `op_t`, qui associe un opérateur (`op`) à la fonction correspondante (`f`), ainsi que les prototypes des fonctions de la calculatrice.
- `3-op_functions.c` : les cinq fonctions d'opération de la calculatrice : `op_add` (somme), `op_sub` (différence), `op_mul` (produit), `op_div` (division) et `op_mod` (reste de la division).
- `3-get_op_func.c` : fonction `get_op_func` qui parcourt un tableau de structures `op_t` et renvoie un pointeur vers la fonction correspondant à l'opérateur `s`, ou `NULL` s'il ne fait pas partie des opérateurs `+`, `-`, `*`, `/` et `%`.
- `3-main.c` : fonction `main` de la calculatrice, qui s'utilise sous la forme `calc num1 operator num2`. Elle convertit les nombres avec `atoi`, récupère la fonction à appeler avec `get_op_func` et affiche le résultat, suivi d'un retour à la ligne. En cas d'erreur, elle affiche `Error` et quitte avec le statut `98` si le nombre d'arguments est incorrect, `99` si l'opérateur est inconnu, et `100` en cas de division ou de modulo par `0`.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
