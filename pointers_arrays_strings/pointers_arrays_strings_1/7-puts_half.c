#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: pointer to the string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len;
	int i;

	len = 0;
	while (str[len] != '\0')
		len++;

	i = (len + 1) / 2;
	while (i < len)
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
