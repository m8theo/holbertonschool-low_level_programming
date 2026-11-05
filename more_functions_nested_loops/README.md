# C - Plus de fonctions, plus de boucles imbriquées

Ce projet contient mon projet **C - Plus de fonctions, plus de boucles imbriquées**, réalisé dans le cadre du programme Holberton School.

Il approfondit l'écriture de fonctions en C, l'utilisation des prototypes et des fichiers d'en-tête, ainsi que les boucles imbriquées pour dessiner des formes dans le terminal (lignes, diagonales, carrés et triangles). L'affichage se fait uniquement avec `_putchar`, sauf pour le programme Fizz-Buzz, qui utilise `printf`.

## Fichiers

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-isupper.c` : fonction `_isupper` qui renvoie `1` si un caractère est une lettre majuscule, `0` sinon.
- `1-isdigit.c` : fonction `_isdigit` qui renvoie `1` si un caractère est un chiffre (de `0` à `9`), `0` sinon.
- `2-mul.c` : fonction `mul` qui multiplie deux entiers et renvoie le résultat.
- `3-print_numbers.c` : fonction `print_numbers` qui affiche les chiffres de `0` à `9`, suivis d'un retour à la ligne.
- `4-print_most_numbers.c` : fonction `print_most_numbers` qui affiche les chiffres de `0` à `9` sauf `2` et `4`, suivis d'un retour à la ligne.
- `5-more_numbers.c` : fonction `more_numbers` qui affiche 10 fois les nombres de `0` à `14`, chaque fois suivis d'un retour à la ligne.
- `6-print_line.c` : fonction `print_line` qui dessine une ligne droite de `n` caractères `_`, suivie d'un retour à la ligne.
- `7-print_diagonal.c` : fonction `print_diagonal` qui dessine une diagonale de `n` caractères `\`.
- `8-print_square.c` : fonction `print_square` qui affiche un carré de `#` de la taille donnée.
- `9-fizz_buzz.c` : programme qui affiche les nombres de `1` à `100`, en remplaçant les multiples de 3 par `Fizz`, les multiples de 5 par `Buzz` et les multiples des deux par `FizzBuzz`.
- `10-print_triangle.c` : fonction `print_triangle` qui affiche un triangle de `#` aligné à droite, de la taille donnée.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
