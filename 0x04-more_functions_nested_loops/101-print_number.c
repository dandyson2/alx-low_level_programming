#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - print number
 * print_number - print
 * @n: integer
 * Return: Always
 */
void print_number(int n)
{

unsigned int n1 = n;
if (n < 0)
{
_putchar('-');
n1 = -n1;
}
if ((n1 / 10) > 0)
print_number(n1 / 10);

_putchar((n1 % 10) + '0');
}
