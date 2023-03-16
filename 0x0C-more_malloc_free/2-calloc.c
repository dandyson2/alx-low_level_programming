#include <stdlib.h>
#include "main.h"
/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: number of elements in array
 * @size: size of elements of array
 * Return: NULL is size of nmemb == 0
 * NULL if fails
 * ptr to memory allocated if succeed
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *v;
	unsigned int y;

	if (nmemb == 0 || size == 0)
		return (NULL);
	v = malloc(nmemb * size);
	if (v == NULL)
	{
		return (NULL);
	}
	for (y = 0; y < (nmemb * size); y++)
	{
		*((char *)(v) + y) = 0;
	}
	return (v);
}
