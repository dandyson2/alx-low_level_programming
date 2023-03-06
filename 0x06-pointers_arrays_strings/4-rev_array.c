#include "main.h"
/**
 * reverse_array - a function that reverses the content of an array of integers
 * @a: array char
 * @n: array numerical elements
 * Return: Nothing
 */
void reverse_array(int *a, int n)
{
	int i;
	int q;

	for (i = 0; i < n--; i++)
	{
		q = a[i];
		a[i] = a[n];
		a[n] = q;
	}
}
