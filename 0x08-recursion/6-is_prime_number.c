#include "main.h"
/**
 * functionPrime - return 0 or 1
 * @num: input to check
 * @i: possible factor
 * Return: 0 if not prime, 1 if prime
 */
int functionPrime(int num, int i)
{
	if (i < num)
	{
		if (num % i == 0)
		{
			return (0);
		}
		else
		{
			return (functionPrime(num, i + 1));
		}
	}
	else
	{
		return (1);
	}
}

/**
 * is_prime_number - function that returns 1 if the input integer
 * is a prime number, otherwise return 0
 * @n: input
 * Return: 1 if number is prime
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else
	{
		return (functionPrime(n, 2));
	}
}
