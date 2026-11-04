#include "main.h"

/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: pointer to the buffer where the string is copied
 * @src: pointer to the string to copy
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
