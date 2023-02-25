#include "main.h"

/**
 * print_number - print number
 * @q:  integer
 * Task: print the integer q
 * Return: void
 */
void print_number(int q);
{

unsigned int num;

if (n < 0)
{
num = - q;
_putchar('-');
}
else
{
num = q;
}
if (num / 10)
{
print_number(num / 10);
}
_putchar((num % 10) + '0');
}
