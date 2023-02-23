#include "main.h"
/**
 * print_diagonal - draws a diagonal line
 * @n: integer
 */
void print_diagonal(int n)
{
int y, z;

if (n <= 0)
{
_putchar('\n')
}
else
{
for (y = 1; y <= n; y++)
{
for (z = 1; z < y; z++)
{
_putchar(' ');
}
_putchar('\\');
_putchar('\n');
}
}
}
