# Laboratoire d'efficacité et de benchmarking Green Tech

Ce projet contient mon projet **Laboratoire d'efficacité et de benchmarking Green Tech**, réalisé dans le cadre du programme Holberton School.

Il couvre la mesure du temps d'exécution d'un programme C avec `clock()` et `CLOCKS_PER_SEC` de l'en-tête `<time.h>`, la comparaison de l'efficacité de deux algorithmes qui donnent le même résultat, l'instrumentation d'un programme pour chronométrer chacune de ses étapes, ainsi que le lien entre temps d'exécution et consommation d'énergie. Le projet ne mesure pas la consommation électrique réelle en watts : le temps d'exécution sert d'indicateur indirect de l'activité du processeur.

## Fichiers

- `baseline_loop.c` : programme de référence qui exécute une boucle de 100 millions d'itérations et affiche son temps d'exécution.
- `baseline_loop-metrics.md` : sorties des trois exécutions de `baseline_loop.c`.
- `comparison_algorithms.c` : programme qui compte les nombres pairs d'un tableau de 50 000 entiers avec deux méthodes, une méthode naïve à boucles imbriquées et une méthode directe en un seul passage, puis affiche le résultat et le temps d'exécution de chacune.
- `comparison_algorithms-metrics.md` : sorties des trois exécutions de `comparison_algorithms.c`.
- `runs.txt` : sorties brutes des trois exécutions de `comparison_algorithms.c`.
- `instrumentation_lab.c` : programme qui génère un jeu de 50 000 données, les transforme puis calcule une somme de contrôle. C'est le seul fichier modifié : des appels à `clock()` ont été ajoutés entre chaque étape pour mesurer séparément `BUILD_DATA`, `PROCESS` et `REDUCE`, ainsi que le temps `TOTAL`, sans inclure l'affichage dans la zone mesurée.
- `instrumentation_runs.txt` : sorties des trois exécutions de `instrumentation_lab.c`.
- `green_efficiency_analysis.md` : rapport écrit en anglais présentant la méthodologie de mesure, les différences de performance observées, la relation entre temps d'exécution et consommation d'énergie, les limites de l'expérience et les enseignements tirés.
- `green_efficiency_analysis_fr.md` : version française du rapport écrit.

## Environnement

- Machine : Apple M1
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`
- Bibliothèques : uniquement la bibliothèque standard C
- Mesure du temps : `clock()` et `CLOCKS_PER_SEC` (`<time.h>`)
