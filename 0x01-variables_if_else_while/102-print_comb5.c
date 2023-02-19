#include <stdio.h>
/**
 * main - main point
 * Task: Displays all possible
 * combinations of two-digit numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	int v, w;

	for (v = 0; v < 100; v++)
	{
		for (w = 0; w < 100; w++)
		{
			if (v < w)
			{
				putchar((v / 10) + 48);
				putchar((v % 10) + 48);
				putchar(' ');
				putchar((w / 10) + 48);
				putchar((w % 10) + 48);
				if (v != 98 || w != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
