#include <stdio.h>

/**
 * print_menu - Affiche les options du menu de la calculatrice sur la console.
 */
void print_menu(void)
{
    printf("1) Addition\n");
    printf("2) Soustraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");
    printf("0) Quitter\n");
    printf("Choisissez:\n");
}

/**
 * read_operands - Lit deux opérandes de l'utilisateur.
 * @a: Pointeur vers le premier opérande.
 * @b: Pointeur vers le deuxième opérande.
 * 
 * Return: 1 en cas de réussite, 0 si aucun nombre n'a pu être lu
 */
int read_operands(double *a, double *b)
{
    printf("Entrez le premier nombre: ");
    if (scanf("%lf", a) != 1)
        return 0;
    printf("Entrez le deuxième nombre: ");
    if (scanf("%lf", b) != 1)
        return 0;
    return 1;
}

/**
 * compute - Effectue l'opération choisie sur les deux opérandes.
 * @choice: L'opération choisie (1 pour addition, 2 pour soustraction, 3 pour multiplication, 4 pour division).
 * @a: Le premier opérande.
 * @b: Le deuxième opérande.
 */
void compute(int choice, double a, double b)
{
    switch (choice)
    {
        case 1:
         printf("Résultat: %g\n", a + b);
          break;
        case 2:
         printf("Résultat: %g\n", a - b);
          break;
        case 3:
         printf("Résultat: %g\n", a * b);
          break;
        default:
          break;
    }
}

/**
 * main - Point d'entrée du programme de la calculatrice.
 * 
 * Return: 0 si le programme se termine avec succès.
 */
int main(void)
{
    int choice;
    double a, b;

    printf("=== Menu de la Calculatrice ===\n");
    while (1)
    {
        print_menu();
        if (scanf("%d", &choice) != 1)
          return (1);
        if (choice == 0)
          break;
        if (choice < 0 || choice > 4)
        {
            printf("Choix invalide. Veuillez réessayer.\n");
            continue;
        }
        if (!read_operands(&a, &b))
            return (1);
        compute(choice, a, b);
    }
    printf("Au revoir!\n");
    return 0;
}
