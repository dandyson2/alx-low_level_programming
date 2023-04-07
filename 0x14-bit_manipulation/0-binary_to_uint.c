#include "main.h"

/**
 * binary_to_uint - function that converts a binary
 * number to an unsigned int
 * @b: The binary
 * Return: unsigned integer
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int define;
	int _unit, max;

	if (!b)
		return (0);

	define = 0;

	for (_unit = 0; b[_unit] != '\0'; _unit++)
		;

	for (_unit--, max = 1; _unit >= 0; _unit--, max *= 2)
	{
		if (b[_unit] != '0' && b[_unit] != '1')
		{
			return (0);
		}
		if (b[_unit] & 1)
		{
			define += max;
		}
	}
	return (define);
}

