#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - print to 98
 * @p: number to start
 * Return: 0 or 1
 */

void print_to_98(int p)
{
	while (p < 98)
	{
		printf("%i, ", p);
		p++;
	}
	while (p > 98)
	{
		printf("%i, ", p);
		p--;
	}
	printf("98");
	putchar('\n');
}
