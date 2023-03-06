#include "main.h"
/**
 * string_toupper - function that changes all lowercase letters of to uppercase
 * @w: ptr
 * Return: w
 */
char *string_toupper(char *w)
{
	int k;

	k = 0;
	while (w[k] != '\0')
	{
		if (w[k] >= 'a' && w[k] <= 'z')
			w[k] = w[k] - 32;
		k++;
	}

	return (w);
}
