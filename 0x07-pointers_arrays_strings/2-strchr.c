#include "main.h"
/**
 * _strchr - a function that locates a character in a string
 * @s: input
 * @c: input
 * Return: 0 Always
 */
char *_strchr(char *s, char c)
{
	int y = 0;

	for (y = 0; s[y] >= '\0'; y++)
	{
		if (s[y] == c)
			return (&s[y]);
	}

	return (0);
}
