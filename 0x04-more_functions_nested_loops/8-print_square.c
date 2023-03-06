#include "main.h"

/**
 * print_square - prints a square
 * @max: size of width and length
 * Return: square '#'
 */
void print_square(int max)
{
int fine, wine;

if (max <= 0)
{
_putchar('\n');
}
else
{
for (fine = 1; fine <= max; fine++)
{
_putchar('#');

for (wine = 2; wine <= max; wine++)
{
_putchar('#');
}
_putchar('\n');
}
}
}
