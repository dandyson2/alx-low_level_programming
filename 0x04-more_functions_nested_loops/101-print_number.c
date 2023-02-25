#include <stdio.h>

/**
 * print_number - print an integer
 * @num:  integer to be printed
 */
void print_number(int num)
{
for (int i = 1; i <= num; i++)
{
for (int j = 1; j <= i; j++)
{
int digit = i % 10;
_putchar(digit + '0');
}
_putchar('\n');
}
}
