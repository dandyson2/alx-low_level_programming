#include "main.h"
#include <stdio.h>
/**
 * void print_diagsums -  function that prints the sum of the two
 * diagonals of a square matrix of integers
 * @a: input
 * @size: input
 * Return: 0 Always
 */
void print_diagsums(int *a, int size)
{
	int cal1, cal2, g;

	cal1 = 0;
	cal2 = 0;

	for (g = 0; g < size; g++)
	{
		cal1 = cal1 + a[g * size + g];
	}
	for (g = size - 1; g >= 0; g--)
	{
		cal1 += a[g * size + (size - g - 1)];
	}
	printf("%d, %d\n", cal1, cal2);
}
