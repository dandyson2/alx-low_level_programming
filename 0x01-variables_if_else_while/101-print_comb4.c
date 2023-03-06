#include <stdio.h>
/**
 * main - main point
 * Task: Displays all possible different
 * combinations of three digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a, b, x;

	for (a = 48; a < 58; a++)
	{
		for (b = 49; b < 58; b++)
		{
			for (x = 50; x < 58; x++)
			{
				if (x > b && b > a)
				{
					putchar(a);
					putchar(b);
					putchar(x);
					if (a != 55 || b != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
