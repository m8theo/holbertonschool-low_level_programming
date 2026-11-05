# C - Fonctions et boucles imbriquées

Ce projet contient mon projet **C - Fonctions et boucles imbriquées**, réalisé dans le cadre du programme Holberton School.

Il couvre l'écriture et l'utilisation de fonctions en C, la différence entre la déclaration et la définition d'une fonction, les prototypes, la portée des variables, les boucles imbriquées, ainsi que l'utilisation d'un fichier d'en-tête avec `#include`. L'affichage se fait uniquement avec `_putchar`, sans la bibliothèque standard.

## Fichiers

- `main.h` : fichier d'en-tête contenant les prototypes de toutes les fonctions du projet, ainsi que celui de `_putchar`.
- `0-putchar.c` : programme qui affiche `_putchar`, suivi d'un retour à la ligne.
- `1-alphabet.c` : fonction `print_alphabet` qui affiche l'alphabet en minuscules, suivi d'un retour à la ligne.
- `2-print_alphabet_x10.c` : fonction `print_alphabet_x10` qui affiche 10 fois l'alphabet en minuscules, chaque fois suivi d'un retour à la ligne.
- `3-islower.c` : fonction `_islower` qui renvoie `1` si un caractère est une lettre minuscule, `0` sinon.
- `4-isalpha.c` : fonction `_isalpha` qui renvoie `1` si un caractère est une lettre, minuscule ou majuscule, `0` sinon.
- `5-sign.c` : fonction `print_sign` qui affiche le signe d'un nombre (`+`, `0` ou `-`) et renvoie `1`, `0` ou `-1`.
- `6-abs.c` : fonction `_abs` qui calcule et renvoie la valeur absolue d'un entier.
- `7-print_last_digit.c` : fonction `print_last_digit` qui affiche le dernier chiffre d'un nombre et renvoie sa valeur.
- `8-24_hours.c` : fonction `jack_bauer` qui affiche chaque minute de la journée, de `00:00` à `23:59`.
- `9-times_table.c` : fonction `times_table` qui affiche la table de multiplication de 0 à 9.
- `10-add.c` : fonction `add` qui additionne deux entiers et renvoie le résultat.
- `11-print_to_98.c` : fonction `print_to_98` qui affiche tous les entiers de `n` à `98`, séparés par `, `, suivis d'un retour à la ligne.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
