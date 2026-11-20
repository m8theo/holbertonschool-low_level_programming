#include <stdio.h>

/**
 * op_func - Type d'un pointeur vers une opération (double, double) -> double
 */
typedef double (*op_func)(double, double);

/**
 * op_add - Additionne deux nombres.
 * @a: Le premier opérande.
 * @b: Le deuxième opérande.
 *
 * Return: a + b
 */
double op_add(double a, double b)
{
	return (a + b);
}

/**
 * op_sub - Soustrait deux nombres.
 * @a: Le premier opérande.
 * @b: Le deuxième opérande.
 *
 * Return: a - b
 */
double op_sub(double a, double b)
{
	return (a - b);
}

/**
 * op_mul - Multiplie deux nombres.
 * @a: Le premier opérande.
 * @b: Le deuxième opérande.
 *
 * Return: a * b
 */
double op_mul(double a, double b)
{
	return (a * b);
}

/**
 * op_div - Divise deux nombres (b != 0 est vérifié par l'appelant).
 * @a: Le premier opérande.
 * @b: Le deuxième opérande.
 *
 * Return: a / b
 */
double op_div(double a, double b)
{
	return (a / b);
}

/**
 * main - Point d'entrée du programme de la calculatrice.
 *
 * Return: 0 en cas de succès, 1 si une saisie est invalide.
 */
int main(void)
{
	op_func ops[] = {NULL, op_add, op_sub, op_mul, op_div};
	int n_ops = (int)(sizeof(ops) / sizeof(ops[0]));
	int choice;
	double a, b;

	printf("Simple Calculator\n");
	while (1)
	{
		printf("1) Add\n2) Subtract\n3) Multiply\n"
		       "4) Divide\n0) Quit\nChoice: ");
		if (scanf("%d", &choice) != 1)
			return (1);
		if (choice == 0)
			break;
		if (choice < 0 || choice >= n_ops || ops[choice] == NULL)
		{
			printf("Invalid choice\n");
			continue;
		}
		printf("A: ");
		if (scanf("%lf", &a) != 1)
			return (1);
		printf("B: ");
		if (scanf("%lf", &b) != 1)
			return (1);
		if (ops[choice] == op_div && b == 0)
			printf("Error: Division by zero!\n");
		else
			printf("Result: %g\n", ops[choice](a, b));
	}
	printf("Bye!\n");
	return (0);
}
