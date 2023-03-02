#include "main.h"
/**
 * leet - a function that encodes a string into 1337speak
 * @h: value
 * Return: h
 */
char *leet(char *h)
{
	int m, n;
	char p1[] = "aAaEoOtTlL";
	char p2[] = "4433007711";

	for (m = 0; h[m] != '\0'; m++)
	{
		for (n = 0; n < 10; n++)
		{
			if (h[m] == p1[n])
			{
				h[m] = p2[n];
			}
		}
	}

	return (h);
}
