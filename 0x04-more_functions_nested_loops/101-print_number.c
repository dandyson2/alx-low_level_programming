#include "main.h"

/**
 * print_number - print an integer
 * @n: integer to be printed
 */
void print_number(int n)
{

unsigned int n3;

if (n < 0)
{
n3 = n;
_putchar('-');
}
else
{
n3 = n;
}

if (n3 / 10)
{
print_numbers(n3 / 10);
}

_putchar((n3 % 10) + '0');
}
