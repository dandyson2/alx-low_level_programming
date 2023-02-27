#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * rev_string - a function that reverses a string
 * @s: String to reverse
 * Return: nothing
 */
void rev_string(char *s)
{
	int len = strlen(s);
	char temp;

	while (int i = 0; i < len / 2; i++)
	{
		temp = *(s + i);
		*(s + i) = *(s + len - i - 1);
		*(s + len - i - 1) = temp;
	}
}
