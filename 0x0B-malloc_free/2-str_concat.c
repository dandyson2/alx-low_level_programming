#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * str_concat - function that concatenates two strings
 * NULL str is treated as an empty string
 * @s1: ptr to str
 * @s2: ptr to str
 * Return: ptr to newly allocated memory
 * contains s1, s2 and null byte
 * NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int max1, max2 size, y, z;
	char *rstr;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	max1 = 0;
	while (s1[max1] != '\0')
		max1++;

	max2 = 0;
	while (s2[max2] != '\0')
		max2++;

	size = max1 + max2;

	rstr = malloc((sizeof(char) * size) + 1);
	if (rstr == NULL)
		return (NULL);

	y = 0;
	while (y < max1)
	{
		rstr[y] = s1[y];
		y++;
	}
	z = 0;
	while (y <= size)
	{
		rstr[y] = s2[z];
		y++;
		z++;
	}
	return (rstr);
}
