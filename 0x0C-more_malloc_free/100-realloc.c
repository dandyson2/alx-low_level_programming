#include <stdlib.h>
#include "main.h"
/**
 * _realloc - function that reallocates a memory
 * block using malloc and free
 * @ptr: ptr to the memory prev allocated
 * @old_size: size in bytes allocated to ptr
 * @new_size: size in bytes of new memory block
 * Return: ptr to new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *cptr;
	unsigned int y;

	if (new_size == old_size)
		return (ptr);
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		cptr = malloc(new_size);
		if (cptr == NULL)
			return (NULL);
	}
	if (new_size > old_size && (ptr != NULL))
	{
		cptr = malloc(new_size);
		if (cptr == NULL)
			return (cptr);
		for (y = 0; y < old_size; y++)
			cptr[y] = *((char *)ptr + 1);
		free(ptr);
	}
	return (cptr);
}
