#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers from min to max included
 * @min: first value of the array
 * @max: last value of the array
 *
 * Return: pointer to the new array, or NULL if min > max
 * or if malloc fails
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = min + i;

	return (array);
}
