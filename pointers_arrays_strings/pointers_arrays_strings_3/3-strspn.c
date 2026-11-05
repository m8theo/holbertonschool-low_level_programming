#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to scan
 * @accept: the set of accepted bytes
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int j;

	while (s[count] != '\0')
	{
		j = 0;
		while (accept[j] != '\0' && accept[j] != s[count])
			j++;

		if (accept[j] == '\0')
			return (count);

		count++;
	}

	return (count);
}
