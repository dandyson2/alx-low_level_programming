#include "main.h"

/**
 * print_times_table - display times table
 * @j: times table to use
 * Return: void
 */

void print_times_table(int j)
{
	int m = 0, rep, n;

	if (j < 0 || j > 15)
		return;

	while (m <= j)
	{
		for (n = 0; n <= j; n++)
		{
			rep = m * n;
			if (n == 0)
				_putchar('0' + rep);
			else if (rep < 10)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + rep);
			}
			else if (rep < 100)
			{
				_putchar(' ');
				_putchar('0' + rep / 10);
				_putchar('0' + rep % 10);
			}
			else
			{
				_putchar('0' + rep / 100);
				_putchar('0' + (rep - 100) / 10);
				_putchar('0' + rep % 10);
			}
			if (n < j)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
		m++;
	}
}
