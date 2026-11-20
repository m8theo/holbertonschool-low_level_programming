# C - Calculatrice simple

Ce projet contient mon projet **C - Calculatrice simple**, réalisé dans le cadre du programme Holberton School.

Il couvre la conception d'un petit programme C complet à partir d'exigences : un menu affiché en boucle avec `while`, la validation du choix de l'utilisateur, la lecture des saisies avec `scanf` et la vérification de sa valeur de retour, la structuration du code en fonctions, l'utilisation d'un tableau de pointeurs de fonctions pour choisir l'opération sans `switch`, les opérations arithmétiques avec les opérateurs de base (`+`, `-`, `*`, `/`), ainsi que la gestion de la division par zéro. La bibliothèque `math.h` n'est pas utilisée.

## Fichiers

- `calculator.c` : programme de calculatrice interactive en ligne de commande. Il contient les éléments suivants :
  - `op_func` : type d'un pointeur vers une fonction qui prend deux `double` et renvoie un `double`.
  - `op_add`, `op_sub`, `op_mul`, `op_div` : une fonction par opération, qui renvoie respectivement `A + B`, `A - B`, `A * B` et `A / B`.
  - `main` : affiche `Simple Calculator` et le menu en boucle jusqu'au choix `0`. Il rejette les choix hors de la plage du tableau `ops`, lit `A` et `B` avec `scanf`, vérifie la division par zéro, puis appelle l'opération avec `ops[choice](a, b)` et affiche `Bye!` à la fin.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## Exécution

```bash
./calculator
```

Saisissez le numéro de l'opération, puis les nombres `A` et `B` quand ils sont demandés. Le résultat s'affiche et le menu revient. Saisissez `0` pour quitter.

```
Simple Calculator
1) Add
2) Subtract
3) Multiply
4) Divide
0) Quit
Choice: 4
A: 10
B: 4
Result: 2.5
```

## Opérations prises en charge

- `1` : addition, `A + B`.
- `2` : soustraction, `A - B`.
- `3` : multiplication, `A * B`.
- `4` : division, `A / B`. Si `B` vaut `0`, le programme affiche `Error: Division by zero!` au lieu de diviser.
- `0` : quitter le programme.

Un choix hors de la plage `0` à `4` affiche `Invalid choice` et le menu est réaffiché.

## Comportement numérique

Le choix du menu est lu comme un entier (`%d`). Les nombres sont lus comme des décimaux de type `double` (`%lf`) et les résultats sont affichés avec `%g`, sans zéros inutiles : `10 / 4` affiche `2.5` et `10 + 25` affiche `35`.

## Limitations connues

- Seules les saisies numériques sont prises en charge. Une saisie non numérique (par exemple `x` ou `hello`) ou la fin de l'entrée (`Ctrl+D`) arrête le programme avec le code de retour `1`, sans message.
- Une saisie comme `1abc` n'est pas entièrement rejetée : `scanf` lit `1` et laisse `abc`, ce qui fait échouer la lecture suivante et arrête le programme.
- Un choix décimal comme `1.5` est lu comme `1`, et `.5` est pris comme premier nombre.
- Les résultats sont affichés avec 6 chiffres significatifs : `1234567` s'affiche `1.23457e+06`.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
