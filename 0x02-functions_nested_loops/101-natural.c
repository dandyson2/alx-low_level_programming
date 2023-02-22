#include <stdio.h>
#include <stdlib>
/**
 * main - main block
 * Task: key and display the sum of all the multiples of 3 or
 * 5 below 1024 (not included), followed by a new line
 * Return: 0
 */
int main(void)
{
	int y = 0;
	int sum = 0;

	while (y < 1024)
	{
		if (y % 3 == 0 || y % 5 == 0)
		{
			sum += y;
		}
		y++;
	}
	printf("%i\n", sum);
	return (0);
}

