# Analyse de l'efficacité des technologies vertes

## Méthodologie de mesure

Tous les programmes ont été compilés avec `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` et exécutés sur le même ordinateur (Apple M1) afin que les résultats soient comparables. Comme il n'existe aucun moyen direct d'évaluer la quantité d'électricité qu'un programme utilise, j'ai mesuré son temps de calcul avec `clock()` depuis l'en-tête `<time.h>`, puis je l'ai divisé par `CLOCKS_PER_SEC` pour l'obtenir en secondes.

Pour `baseline_loop.c` et `comparison_algorithms.c`, j'ai exécuté chaque programme trois fois d'affilée sans modifier le code. J'ai ensuite stocké les sorties et j'en ai fait la moyenne.

Le seul fichier que j'ai modifié est `instrumentation_lab.c`. J'ai ajouté un appel à `clock()` juste avant la première étape, puis à nouveau après chaque étape, comme les temps intermédiaires d'une course. Remarquez que le début de chaque étape coïncide exactement avec la fin de la précédente, donc `TOTAL` est la somme de `BUILD_DATA`, `PROCESS` et `REDUCE`. Je ne fais pas de `printf` dans la zone mesurée parce que je voulais chronométrer uniquement le calcul, et non l'affichage. J'ai rencontré un problème : au début, le programme n'affichait rien. Le fichier qui avait été modifié n'avait pas encore été enregistré et c'est l'ancienne version qui tournait. J'ai réécrit le fichier, je l'ai recompilé, et voilà, ça a fonctionné.

## Différences de performance observée

**Boucle de référence (100 M d'itérations) :** 0,126 s, 0,095 s et 0,094 s, soit ~**0,105 s** en moyenne. La première exécution a été moins rapide que les deux autres. L'ordinateur fait autre chose en parallèle, donc le même calcul ne prend jamais exactement la même durée.

**Comparaison des méthodes (50 000 nombres) :**

| Méthode | Temps moyen |
| --- | --- |
| Naïve | ~2,18 s |
| Directe | ~0,00009 s |

Par conséquent, 2,18 / 0,00009 ≈ 24 000, ce qui rend la méthode naïve environ **24 000 fois plus lente**, bien que les deux donnent la même réponse. En jetant un coup d'œil au code, cela semble parfaitement logique. La méthode naïve recommence à zéro à chaque itération, de sorte qu'elle doit examiner environ 1,25 milliard de valeurs au total (50 000 × 50 001 / 2). La méthode directe n'en vérifie que 50 000. Cela fait donc environ 25 000 fois plus de travail, ce qui est dans la même fourchette que ce que j'ai mesuré.

**Instrumentation :** `TOTAL` = **0,00068 s**, `BUILD_DATA` ~52 %, `PROCESS` ~28 %, `REDUCE` ~20 %. L'étape la plus coûteuse est la préparation des données.

## Relation entre temps d'exécution et consommation d'énergie

Ce projet ne mesure pas les watts. Le temps d'exécution est une métrique indirecte : plus le processeur travaille longtemps, plus il consomme d'énergie. Avec ce concept, la méthode naïve, qui a fait travailler le processeur pendant environ 2,18 s au lieu de 0,00009 s, est clairement celle qui a gaspillé le plus d'énergie dans mes tests. En bref, une mauvaise méthode peut gaspiller énormément de temps, et donc énormément d'énergie.

## Limites de l'expérience

- Ce n'est pas vraiment une mesure en watts. Le temps d'exécution n'est qu'une estimation, et la puissance électrique d'un processeur est rarement constante.
- `clock()` n'est pas très précis pour des durées très courtes (0,00009 s, 0,00068 s). Ces chiffres sont donc plus douteux que les 2,18 s de la méthode naïve.
- J'ai seulement fait la moyenne de trois essais par programme, ce qui est assez faible : une seule exécution peut fausser la moyenne (0,126 s pour la première exécution de référence).
- Tout a été mesuré sur une seule machine (Apple M1), et les résultats pourraient être différents sur un autre ordinateur.

## Enseignement pratique pour l'ingénierie

Mesurer avant d'optimiser : sans les temps intermédiaires, je n'aurais jamais su que la préparation des données prend environ la moitié du temps dans `instrumentation_lab.c`. L'essentiel est simplement d'utiliser la bonne méthode : passer de la méthode naïve à la méthode directe a divisé le temps par environ 24 000 ! Un programme plus rapide est un programme qui consomme moins d'énergie, et c'est l'idée générale de la Green Tech.