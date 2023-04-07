#include "main.h"

/**
 * clear_bit - function that sets the value of a bit 
 * to 0 at a given index
 * @n: ptr to unsigned long integer
 * @index: Bit index
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int y;

	if (index > 63)
		return (-1);

	y = 1 << index;

	if (*n & y)
		*n ^= y;

	return (1);
}
