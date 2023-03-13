#include "main.h"
#include <stdlib.h>
/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @str: ptr to string
 * Return: NULL if str is NULL
 * Pointer to duplicate str
 * NULL if memory is not enough
 */
char *_strdup(char *str)
{
	char *rstr;
	unsigned int max, x;

	if (str == NULL)
	{
		return (NULL);
	}
	max = 0;
	while (str[max] != '\0')
	{
		max++;
	}
	rstr = malloc(sizeof(char) * (max + 1));

	if (rstr == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < max; x++)
	{
		rstr[x] = str[x];
	}
	rstr[max] = '\0';
	return (rstr);
}


