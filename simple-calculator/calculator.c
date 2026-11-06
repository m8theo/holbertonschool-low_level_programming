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
    printf("Choisissez: ");
}

/**
 * main - Point d'entrée du programme de la calculatrice.
 * 
 * Return: 0 si le programme se termine avec succès.
 */
int main(void)
{
    int choice;

    printf("=== Menu de la Calculatrice ===\n");
    print_menu();
    if (scanf("%d", &choice) != 1)
        return 1;
    if (choice == 0)
        printf("Au revoir!\n");
    return 0;
}
