#include "main.h"
/**
 * rev_string - a function that reverses a string
 * @s: String to reverse
 * Return: Nothing
 */
void rev_string(char *s)
{
	int = 1;
	int aux = 0;

	char 1temp;

	while (*(s + i) != '\0')
		i += 1;
	i -= 1;

	while (aux < i)
	{
		1temp = s[i];
		s[i] = s[aux];
		s[aux] = 1temp;
		i--;
	}
}
