#include <stdlib.h>
#include "main.h"
/**
 * array_range - function that creates an array of integers
 * @min: minimal value
 * @max: maximal value
 * Return: ptr to newly created array
 * NULL if malloc fails
 * NULL if min > max
 */
int *array_range(int min, int max)
{
	int number, y;
	int *r;

	number = 0;

	if (min > max)
		return (NULL);

	number = ((max + 1) - min);

	r = malloc(number * sizeof(int));

	if (r == NULL)
		return (NULL);

	for (y = 0; y < number; y++)
	{
		*(r + y) = min + y;
	}
	return (r);
}
