#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenates s1 and the first n bytes of s2
 * @s1: first string (NULL is treated as an empty string)
 * @s2: second string (NULL is treated as an empty string)
 * @n: maximum number of bytes of s2 to use
 *
 * Return: pointer to the new string, or NULL if malloc fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (n > len2)
		n = len2;

	s = malloc(sizeof(char) * (len1 + n + 1));
	if (s == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		s[i] = s1[i];
	for (j = 0; j < n; j++)
		s[i + j] = s2[j];
	s[i + j] = '\0';

	return (s);
}
