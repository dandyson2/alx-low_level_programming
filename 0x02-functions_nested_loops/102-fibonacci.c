#include <stdio.h>
/**
 * main - main block
 * Task: key in and display the sum of all the multiple of 3
 * or 5 below 1024 (not included), followed by a new line
 * Return: 0
 */
int main(void)
{
	int w = 0;
	long int s = 0, t = 1, next;

	while (w < 50)
	{
		next = s + t;
		s = t;
		t = next;
		printf("%lu", next);

		if (w < 49)
		{
			printf(", ");
		}
		w++;
	}
	putchar('\n');
	return (0);
}
