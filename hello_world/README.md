# C - Hello, World

Ce projet contient mon projet **C - Hello, World**, réalisé dans le cadre du programme Holberton School.

Il couvre les étapes de la compilation d'un programme C avec `gcc` (préprocesseur, compilateur, assembleur, édition de liens), l'affichage de texte avec `puts` et `printf`, et la taille des types avec l'opérateur `sizeof`.

## Fichiers

- `0-preprocessor` : script qui fait passer le fichier C contenu dans `$CFILE` par le préprocesseur et enregistre le résultat dans le fichier `c`.
- `1-compiler` : script qui compile le fichier C contenu dans `$CFILE` sans faire l'édition de liens, et produit un fichier `.o`.
- `2-assembler` : script qui génère le code assembleur du fichier C contenu dans `$CFILE` dans un fichier `.s`.
- `3-name` : script qui compile le fichier C contenu dans `$CFILE` et crée un exécutable nommé `cisfun`.
- `4-puts.c` : programme qui affiche une phrase avec `puts`, suivie d'un retour à la ligne.
- `5-printf.c` : programme qui affiche une phrase avec `printf`, suivie d'un retour à la ligne.
- `6-size.c` : programme qui affiche la taille des types `char`, `int`, `long int`, `long long int` et `float` sur la machine où il est compilé.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
