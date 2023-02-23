#include "main.h"
/**
 * print_triangle - function that prints a triangle
 * @max: size of triangle
 * Return: '#'s
 */
void print_triangle(int max)
{
int wa, zo, bi;
if (max <= 0)
{
_putchar('\n');
}
else
{
for (zo = 0; zo <= (max - 1); zo++)
{
for (wa = 0; wa < (max - 1) - zo; wa++)
{
_putchar(' ');
}
for (bi = 0; bi <= zo; bi++)
{
_putchar('#');
}
_putchar('\n');
}
}
}
