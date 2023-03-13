#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * str_concat - concates two strings
 * NULL str is treated as an empty string
 * @s1: ptr to str
 * @s2: ptr to str
 * Return: ptrr to newly allocated memory which has
 * s1, s2 and null byte
 * NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1, len2, size, y, z;
	char *nstr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	size = len1 + len2;

	nstr = malloc((sizeof(char) * size) + 1);
	if (nstr == NULL)
		return (NULL);
	y = 0;
	while (y < len1)
	{
		nstr[y] = s1[y];
		y++;
	}
	z = 0;
	while (y <= size)
	{
		nstr[y] = s2[z];
		y++;
		z++;
	}
	return (nstr);
}

