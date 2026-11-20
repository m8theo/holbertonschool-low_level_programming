#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the size of the triangle
 *
 * Description: if size is 0 or less, only a new line is printed
 * Return: void
 */
void print_triangle(int size)
{
	int row, i;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (row = 1; row <= size; row++)
	{
		for (i = 0; i < size - row; i++)
			_putchar(' ');
		for (i = 0; i < row; i++)
			_putchar('#');
		_putchar('\n');
	}
}
