#include "main.h"

/**
 * print_sign - function that displays the sign of a number.
 * @a: The character number to check
 * Return: int
 */
int print_sign(int a)
{
	if (a > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (a < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
}
