#include "main.h"
#include <stdio.h>
/**
 * infinite_add - a function that adds two numbers
 * @r: buffer
 * @size_r: buffer size
 * @n1: number
 * @n2: number
 * Return: r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, y = 0, z = 0, digits = 0;
	int val1 = 0, val2 = 0, temp_tot = 0;

	while (*(n1 + y) != '\0')
		i++;
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
