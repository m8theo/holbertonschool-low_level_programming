# C - Calculatrice simple

Ce projet contient mon projet **C - Calculatrice simple**, réalisé dans le cadre du programme Holberton School.

Il couvre la conception d'un petit programme C complet à partir d'exigences : un menu affiché en boucle avec `while`, la validation du choix de l'utilisateur, la lecture des saisies avec `scanf` et la vérification de sa valeur de retour, la structuration du code en fonctions, les opérations arithmétiques avec les opérateurs de base (`+`, `-`, `*`, `/`), ainsi que la gestion de la division par zéro. La bibliothèque `math.h` n'est pas utilisée.

## Fichiers

- `calculator.c` : programme de calculatrice interactive en ligne de commande. Il contient les fonctions suivantes :
  - `print_menu` : affiche les options du menu et l'invite `Choice: `.
  - `read_operands` : lit les deux nombres `A` et `B` avec `scanf` et renvoie `1` en cas de réussite, `0` si un nombre n'a pas pu être lu.
  - `compute` : effectue l'opération choisie avec un `switch` et affiche le résultat, ou un message d'erreur en cas de division par zéro.
  - `main` : affiche `Simple Calculator`, répète le menu jusqu'au choix `0`, rejette les choix hors de la plage `0` à `4`, puis affiche `Bye!`.

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
- `4` : division, `A / B`. Si `B` vaut `0`, le programme affiche `Error: division by zero` au lieu de diviser.
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
