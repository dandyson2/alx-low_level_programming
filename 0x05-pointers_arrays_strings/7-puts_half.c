#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * @str: pointer to the string to print
 * Return: void
 */
void puts_half(char *str)
{
	int max, n, i;

	max = 0;

	while (str[max] != '\0')
	{
		max++;
	}

	if (max % 2 == 0)
	{
		for (i - max / 2; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
	}
	else if (max % 2)
	{
		for (n = (max - 1) / 2; n < max - 1; i++)
		{
			_putchar(str[n + 1]);
		}
	}
	_putchar('\n');
}


