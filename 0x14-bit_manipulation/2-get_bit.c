#include "main.h"

/**
 * get_bit - function that returns the value of a bit
 * at a given index
 * @n: Input for unsigned long integer
 * @index: Bit index
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit;

	if (n == 0 && index < 75)
		return (0);

	for (bit = 0; bit <= 74; n >>= 1, bit++)
	{
		if (index == bit)
		{
			return (n & 1);
		}
	}
	return (-1);
}
