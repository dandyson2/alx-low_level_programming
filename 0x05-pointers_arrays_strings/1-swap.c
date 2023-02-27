#include "main.h"
/**
 * swap_int - function that swaps the values of two integers
 * @m: int to swap
 * @n: int to swap
 */
void swap_int(int *m, int *n)
{
	int q;

	q = *m;
	m = *n;
	n = q;
}
