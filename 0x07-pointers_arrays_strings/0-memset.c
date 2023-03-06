#include "main.h"
/**
 * *_memset - a function that fills memory with a constant byte
 * @n: number of bytes to change
 * @s: adress of memory to fill
 * @b: the desired value
 * Return: changed arrays
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}

	return (s);
}
