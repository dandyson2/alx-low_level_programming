#include <stdlib.h>
<<<<<<< HEAD
#include <time.h>
#include <stdio.h>
/**
 * main - Displays the last digit of a randomly generated number
 * and if it is greater than 5, less than 6, or 0.
=======
#include <stdio.h>
#include <time.h>
/**
 * main - Displays the last digit of a randomly generated number and
 * if it is greater than 5, or less than 6, or 0.
>>>>>>> ee696abf6ab2aa6f70142cf7599ba90385d097ac
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

<<<<<<< HEAD

=======
>>>>>>> ee696abf6ab2aa6f70142cf7599ba90385d097ac
	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if ((n % 10) > 5)
	{
<<<<<<< HEAD
		printf("Last digit of %d is %d and is greater than 5\n", n, n % 10);
	}
	else if ((n % 10) < 6 && (n % 10) != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, n % 10);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n", n, n % 10);
=======
		printf("Last digit of %d is %d and is greater than 5\n",
				n, n % 10);
	}
	else if ((n % 10) < 6 && (n % 10))
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n",
				n, n % 10);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n",
				n, n % 10);
>>>>>>> ee696abf6ab2aa6f70142cf7599ba90385d097ac
	}
	return (0);
}
