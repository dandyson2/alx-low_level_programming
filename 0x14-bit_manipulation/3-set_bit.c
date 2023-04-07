#include "main.h"

/**
 * set_bit - function that sets the value of a bit
 * to 1 at a given index
 * @n: ptr to unsigned long integer
 * @index: Bit index
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bit;

	if (index > 63)
		return (-1);

	bit = 1 << index;

	*n = (*n | bit);

	return (1);
}
