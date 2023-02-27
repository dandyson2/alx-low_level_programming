#include "main.h"
/**
 * rev_string - a function that reverses a string
 * @s: String to reverse
 * Return: nothing
 */
void rev_string(char *s)
{
	char *begin = s;
	char *end = s + strlen(s) - 1;

	while (begin < end)
	{
		char temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}
