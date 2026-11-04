#include "main.h"

/**
 * _strncpy - copies at most n bytes of a string
 * @dest: the destination buffer
 * @src: the string to copy
 * @n: the maximum number of bytes to copy from src
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
