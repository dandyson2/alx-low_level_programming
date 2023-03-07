#include "main.h"
#include <stdio.h>
/**
 * print_number - function that prints an integer
 * @n: input
 * Return: void
 */
void print_number(int n)
{
unsigned int f;

if (n < 0)
{
_putchar('-');
f = -n;
}
else
{
f = n;
}
if (f / 10 != 0)
print_number(f / 10);
_putchar((f % 10) + '0');
}
