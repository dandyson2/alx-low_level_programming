#include "main.h"
/**
 * mockRecursion - function sqrt
 * @num: number
 * @nSqrt: likely sqrt of number
 * Return: sqrt of number -1 for error
 */
int mockRecursion(int num, int nSqrt)
{
	if ((nSqrt * nSqrt) == num)
	{
		return (nSqrt);
	}
	else
	{
		if ((nSqrt * nSqrt) > num)
			return (-1);
		else
			return (mockRecursion(num, nSqrt + 1));
	}
}

#include "main.h"
/**
 * _sqrt_recursion - Your subconscious is looking for the dreamer
 * @n: input
 * Return: sqrt of n
 * -1 if n does not have a natural sqrt
 */
int _sqrt_recursion(int n)
{

	if (n < 0)
		return (-1);
	else
		return (mockRecursion(n, 0));
}
