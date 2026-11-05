# C - Visualiser le débogage avec Python Tutor

Ce projet contient mon projet **C - Visualiser le débogage avec Python Tutor**, réalisé dans le cadre du programme Holberton School.

Il couvre le débogage de programmes C qui compilent sans erreur mais produisent un résultat faux. Chaque programme est exécuté pas à pas dans le visualiseur C de Python Tutor pour observer la valeur des variables, les itérations des boucles et les valeurs de retour des fonctions, puis pour identifier et corriger des erreurs de logique courantes : condition de boucle décalée d'une unité (off-by-one), variable de contrôle modifiée deux fois, accumulation au mauvais niveau et mauvaise valeur de retour.

## Fichiers

- `sum_to_n.c` : programme qui calcule la somme des entiers de 1 à `n`. Correction de la condition de boucle (`i <= n` au lieu de `i < n`) et de la valeur de retour (`sum` au lieu de `n`).
- `multiplication_table.c` : programme qui affiche une table de multiplication de taille 4. Suppression de l'incrément en trop de la variable `col` dans le corps de la boucle imbriquée, qui faisait sauter une colonne sur deux.
- `row_sums.c` : programme qui calcule la somme de toutes les lignes d'une grille de 3 x 3. Réaffectation de `current` à chaque tour (`=` au lieu de `+=`) pour que chaque ligne ne soit comptée qu'une seule fois.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Outil de débogage : [Python Tutor - Visualiseur C](https://pythontutor.com/c.html)
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`
