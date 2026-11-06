#include <stdio.h>

/**
 * print_menu - Affiche les options du menu de la calculatrice sur la console.
 */
void print_menu(void)
{
    printf("1) Add\n");
    printf("2) Subtract\n");
    printf("3) Multiply\n");
    printf("4) Divide\n");
    printf("0) Quit\n");
    printf("Choice: ");
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
    printf("A: ");
    if (scanf("%lf", a) != 1)
        return (0);
    printf("B: ");
    if (scanf("%lf", b) != 1)
        return (0);
    return (1);
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
         printf("Result: %g\n", a + b);
          break;
        case 2:
         printf("Result: %g\n", a - b);
          break;
        case 3:
         printf("Result: %g\n", a * b);
          break;
        case 4:
         if (b == 0)
         printf("Error: Division by zero!\n");
        else
         printf("Result: %g\n", a / b);
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

    printf("Simple Calculator\n");
    while (1)
    {
        print_menu();
        if (scanf("%d", &choice) != 1)
          return (1);
        if (choice == 0)
          break;
        if (choice < 0 || choice > 4)
        {
            printf("Invalid choice\n");
            continue;
        }
        if (!read_operands(&a, &b))
            return (1);
        compute(choice, a, b);
    }
    printf("Bye!\n");
    return 0;
}
