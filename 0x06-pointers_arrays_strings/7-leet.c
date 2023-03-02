#include "main.h"
/**
 * leet - a function that encodes a string into 1337speak
 * @n: value
 * Return: n
 */
char *leet(char *n)
{
	int y, z;
	char s1[] = "aAaEoOtTlL";
	char s2[] = "4433007711";

	for (y = 0; n[y] != '\0'; y++)
	{
		for (y = 0; y < 10; y++)
		{
			if (n[y] == s1[z])
			{
				n[y] = s2[z];
			}
		}
	}

	return (n);
}
