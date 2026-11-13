# C - Structures, typedef

Ce projet contient mon projet **C - Structures, typedef**, réalisé dans le cadre du programme Holberton School.

Il couvre la définition et l'utilisation des structures en C avec le mot-clé `struct`, l'accès aux membres d'une structure avec l'opérateur `.` et, à partir d'un pointeur, avec l'opérateur `->`, ainsi que la création d'un alias de type avec `typedef`. Il aborde aussi l'allocation dynamique d'une structure avec `malloc`, la copie des chaînes de caractères qu'elle contient, et la libération de toute la mémoire associée avec `free`.

## Fichiers

- `dog.h` : fichier d'en-tête contenant la définition de la structure `struct dog`, composée des membres `name` (`char *`), `age` (`float`) et `owner` (`char *`), l'alias de type `dog_t` pour `struct dog`, ainsi que les prototypes de toutes les fonctions du projet.
- `1-init_dog.c` : fonction `init_dog` qui initialise une variable de type `struct dog` avec le nom, l'âge et le propriétaire donnés. Elle ne fait rien si `d` vaut `NULL`.
- `2-print_dog.c` : fonction `print_dog` qui affiche les membres d'une variable de type `struct dog`, au format `Name: `, `Age: ` et `Owner: `, un par ligne. Si un membre de type chaîne vaut `NULL`, elle affiche `(nil)` à sa place. Si `d` vaut `NULL`, elle n'affiche rien.
- `4-new_dog.c` : fonction `new_dog` qui crée un nouveau chien et renvoie un pointeur vers une structure `dog_t` nouvellement allouée. Elle enregistre une copie de `name` et de `owner` dans de la mémoire allouée, et renvoie `NULL` si une allocation échoue, après avoir libéré la mémoire déjà allouée.
- `5-free_dog.c` : fonction `free_dog` qui libère un chien créé par `new_dog`, en libérant d'abord les chaînes `name` et `owner`, puis la structure elle-même.

## Environnement

- Système : Ubuntu 20.04 LTS
- Compilateur : `gcc` avec les options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Outil de vérification de la mémoire : `valgrind`
- Style de code : Betty
- Éditeurs : `vi`, `vim`, `VS Code`