#include "main.h"

/**
 * more_numbers - print 10 times the numbers from 0 to 14
 * Return: 0
 */

void more_numbers(void)
{
int m, n;

for (n = 0; n < 10; n++)
{
for (m = 0; m <= 14; m++)
{
if (m >= 10)
{
_putchar((m / 10) + '0');
}
_putchar((m % 10) + '0');
}
}
_putchar('\n');
}
