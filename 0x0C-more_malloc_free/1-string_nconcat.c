#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strlen - calculate and return str length
 * @string: - str
 * Return: str length
 */
int _strlen(char *string)
{
	int y;

	for (y = 0; string[y] != '\0'; y++)
		;
	return (y);
}
/**
 * string_nconcat - function that concatenates two strings
 * @s1: str 1
 * @s2: str 2
 * @n: n bytes to concat from string 2
 * Return: ptr to concatd str
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	int number, max, y, z;

	number = n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (number < 0)
		return (NULL);
	if (number >= _strlen(s2))
		number = _strlen(s2);

	max = _strlen(s1) + number + 1;

	ptr = malloc(sizeof(*ptr) * max);
	if (ptr == NULL)
		return (NULL);

	for (y = 0; s1[y] != '\0'; y++)
		ptr[y] = s1[y];
	for (z = 0; z < number; z++)
		ptr[y + z] = s2[z];
	ptr[y + z] = '\0';

	return (ptr);
}
