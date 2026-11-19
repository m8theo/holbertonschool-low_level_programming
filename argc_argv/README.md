# C - argc, argv

Ce projet contient mon projet **C - argc, argv**, réalisé dans le cadre du programme Holberton School.

Il couvre l'utilisation des arguments passés à un programme C depuis la ligne de commande, avec les paramètres `argc` (nombre d'éléments de `argv`, nom du programme compris) et `argv` (tableau des chaînes de caractères des arguments, dont `argv[0]` est le nom du programme). Il aborde aussi les deux prototypes de `main`, `int main(void)` quand le programme n'a pas besoin d'arguments et `int main(int argc, char *argv[])` quand il doit les récupérer, ainsi que l'utilisation de `__attribute__((unused))` ou d'un transtypage en `(void)` pour compiler sans erreur un programme dont un paramètre n'est pas utilisé. La bibliothèque standard est autorisée.

## Fichiers

- `main.h` : fichier d'en-tête contenant le prototype de `_putchar`. Chaque programme ne contenant que `main`, aucun autre prototype n'est nécessaire.
- `0-whatsmyname.c` : programme qui affiche son nom, tel qu'il a été tapé dans le terminal et chemin compris (`argv[0]`), suivi d'un retour à la ligne. Si l'exécutable est renommé, il affiche le nouveau nom sans avoir à être recompilé. Le paramètre `argc`, inutilisé, est marqué avec `__attribute__((unused))`.
- `1-args.c` : programme qui affiche le nombre d'arguments qui lui sont passés (`argc - 1`), suivi d'un retour à la ligne. Le paramètre `argv`, inutilisé, est neutralisé avec `(void)argv;`.
- `2-args.c` : programme qui affiche tous les arguments qu'il reçoit, y compris le nom du programme, un par ligne.
- `3-mul.c` : programme qui multiplie deux nombres convertis avec `atoi` et affiche le résultat, suivi d'un retour à la ligne. S'il ne reçoit pas exactement deux arguments, il affiche `Error` et renvoie `1`.
- `4-add.c` : programme qui additionne des nombres positifs et affiche le résultat, suivi d'un retour à la ligne. Il affiche `0` si aucun nombre n'est passé. Si un argument contient un symbole qui n'est pas un chiffre (y compris le signe `-`), il affiche `Error` et renvoie `1`.

## Compilation et exécution

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-mul.c -o mul
./mul 2 -3
-6
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-add.c -o add
./add 1 10 100 1000
1111
```

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
