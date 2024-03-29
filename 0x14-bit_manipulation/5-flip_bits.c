#include "main.h"

/**
 * flip_bits - function that returns the number of bits
 * you would need to flip to get from one number to another.
 * @n: First number
 * @m: Second number
 * Return: Number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int _flips;

	for (_flips = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			_flips++;
	}
	return (_flips);
}
