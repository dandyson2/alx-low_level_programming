#include <stdlib.h>
/**
 * malloc_checked - function that allocates memory using malloc
 * @b: memory size allocated
 * Return: ptr to assigned memory
 */
void *malloc_checked(unsigned int b)
{
	void *m = malloc(b);

	if (m == NULL)
		exit(98);
	return (m);
}
