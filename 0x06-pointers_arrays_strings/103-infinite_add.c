#include "main.h"
/**
 * rev_string - reverse array
 * @n: integer parameters
 * Return: 0
 */

void rev_string(char *n)
{
	int y = 0;
	int z = 0;
	char temp;

	while (*(n + y) != '\0')
	{
		y++;
	}
	y--;

	for (z = 0; z < y; z++, y--)
	{
		temp = *(n + z);
		*(n + z) = *(n + y);
		*(n + y) = temp;
	}
}

/**
 * infinite_add - a function that adds two number together
 * @n1: first number
 * @n2: second number
 * @r: buffer
 * @size_r: buffer size
 * Return: pointer to call
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, y = 0, z = 0, digits = 0;
	int val1 = 0, val2 = 0, temp_tot = 0;

	while (*(n1 + y) != '\0')
		y++;
	while (*(n2 + z) != '\0')
		z++;
	y--;
	z--;
	if (z >= size_r || y >= size_r)
		return (0);
	while (z >= 0 || y >= 0 || overflow == 1)
	{
		if (y < 0)
			val1 = 0;
		else
			val1 = *(n1 + y) - '0';
		if (z < 0)
			val2 = 0;
		else
			val2 = *(n2 + z) - '0';
		temp_tot = val1 + val2 + overflow;
		if (temp_tot >= 10)
			overflow = 1;
		else
			overflow = 0;
		if (digits >= (size_r - 1))
			return (0);
		*(r + digits) = (temp_tot % 10) + '0';
		digits++;
		z--;
		y--;
	}
	if (digits == size_r)
		return (0);
	*(r + digits) = '\0';
	rev_string(r);
	return (r);
}
