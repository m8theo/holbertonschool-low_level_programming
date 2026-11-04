#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
static int is_separator(char c)
{
	char *separators = " \t\n,;.!?\"(){}";
	int i = 0;

	while (separators[i] != '\0')
	{
		if (c == separators[i])
			return (1);
		i++;
	}

	return (0);
}

/**
 * cap_string - capitalizes the first letter of each word of a string
 * @str: the string to modify
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' &&
		    (i == 0 || is_separator(str[i - 1])))
			str[i] = str[i] - ('a' - 'A');
		i++;
	}

	return (str);
}
