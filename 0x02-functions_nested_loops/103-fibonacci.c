#include <stdio.h>
/**
 * main - main block
 * Task: key in and display even numbers < 4,000,000
 * 5 below 1024 (not included), followed by a new line
 * Return: 0
 */
int main(void)
{
	int f = 0, g = 1, next = 0;
	int sum = 0;

	while (next < 4000000)
	{
		next = f + g;
		f = g;
		g = next;
		if (next % 2 == 0)
			sum += next;
	}
	printf("%i\n", sum);
	return (0);
}
