#include "main.h"

/**
 * times_table - displays times table
 * Return: void
 */

void times_table(void)
{
	int u = 0;
	int v;
	int rep;

	while (u <= 9)
	{
		v = 0;
		while (v <= 9)
		{
			rep = u * v;
			if (v == 0)
			{
				_putchar('0' + rep);
			}
			else if (rep < 10)
			{
				_putchar(' ');
				_putchar('0' + rep);
			}
			else
			{
				_putchar('0' + rep / 10);
				_putchar('0' + rep % 10);
			}
			if (v < 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			v++;
		}
		_putchar('\n');
		u++;
	}
}
