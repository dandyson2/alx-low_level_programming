#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * main - Prints the last digit of a randomly generated number and
 * if it is greater than 5, or less than 6, or 0.
 * Return: Always 0 (Success)
 */
int maim(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if ((n % 10) > 5)
	{
		printf("Last digit of %d is %d and it is greater than 5\n", 
				n, n % 10);
	}
	else if ((n % 10) < 6 && (n % 10) != 0)
	{
		printf("Last digit of %d of %d and it is less than 6 and not 0\n", 
				n, n % 10);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n", 
				n, n % 10);
	}
	return (0);
}
