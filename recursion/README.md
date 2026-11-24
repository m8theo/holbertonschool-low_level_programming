# C - Récursivité

Ce projet contient mon projet **C - Récursivité**, réalisé dans le cadre du programme Holberton School.

Il couvre la récursivité en C : ce qu'est une fonction récursive, comment la mettre en œuvre avec un cas de base qui arrête les appels et un cas récursif qui s'en rapproche à chaque appel, ainsi que les situations dans lesquelles l'utiliser ou non. Toutes les fonctions sont écrites sans aucune boucle et sans variable `static`. Quand le prototype imposé ne suffit pas, une fonction auxiliaire reçoit en paramètre la valeur à faire évoluer d'un appel à l'autre. L'affichage se fait uniquement avec `_putchar`, sans la bibliothèque standard.

## Fichiers

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, y compris les fonctions auxiliaires `_sqrt_helper` et `_prime_helper`, ainsi que celui de `_putchar`.
- `0-puts_recursion.c` : fonction `_puts_recursion` qui affiche une chaîne de caractères, suivie d'un retour à la ligne, comme `puts`.
- `1-print_rev_recursion.c` : fonction `_print_rev_recursion` qui affiche une chaîne de caractères à l'envers. L'appel récursif est fait avant l'affichage du caractère courant, qui a donc lieu en remontant la pile d'appels.
- `2-strlen_recursion.c` : fonction `_strlen_recursion` qui renvoie la longueur d'une chaîne de caractères, comme `strlen`.
- `3-factorial.c` : fonction `factorial` qui renvoie la factorielle d'un nombre. La factorielle de `0` vaut `1`, et la fonction renvoie `-1` si `n` est négatif.
- `4-pow_recursion.c` : fonction `_pow_recursion` qui renvoie la valeur de `x` élevé à la puissance `y`, ou `-1` si `y` est négatif.
- `5-sqrt_recursion.c` : fonction `_sqrt_recursion` qui renvoie la racine carrée entière d'un nombre, ou `-1` s'il n'en a pas. La fonction auxiliaire `_sqrt_helper` teste les candidats un par un et s'arrête dès que leur carré dépasse `n`.
- `6-is_prime_number.c` : fonction `is_prime_number` qui renvoie `1` si un entier est un nombre premier, `0` sinon. La fonction auxiliaire `_prime_helper` cherche un diviseur de `2` jusqu'à la racine carrée de `n`.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
