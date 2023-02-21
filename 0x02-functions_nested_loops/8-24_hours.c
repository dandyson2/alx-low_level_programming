#include "main.h"

/**
 * jack_bauer - displays every minute of the day of Jack Bauer
 * Return: void
 */

void jack_bauer(void)
{
	int h1;
	int h2;
	int k1;
	int k2;
	int a = 9;

	h2 = 0;

	while (h2 <= 2)
	{
		if (h2 == 2)
		{
			/*disengage at 23hrs, not 25*/
			a = 3;
		}
		h1 = 0;
		while (h1 <= a)
		{
			k2 = 0;
			while (k2 <= 5)
			{
				k1 = 0;
				while (k1 <= 9)
				{
					_putchar('0' + h2);
					_putchar('0' + h1);
					_putchar(':');
					_putchar('0' + k2);
					_putchar('0' + k1);
					_putchar('\n');
					k1++;
				}
				k2++;
			}
			h1++;
		}
		h2++;
}
