#include <stdio.h>
#include <stdlib.h>
/**
 * word_count - count number of words in a str
 * @s: ptr to str
 * Return: number of words in str
 */
int word_count(char *s)
{
	int logo, m, n;

	logo = 0;
	n = 0;

	for (m = 0; s[m] != '\0'; m++)
	{
		if (s[m] == ' ')
			logo = 0;
		else if (logo == 0)
		{
			logo = 1;
			n++;
		}
	}
	return (n);
}
/**
 * strtow - function that splits a string into words
 * @str: str to split
 * Return: ptr to an array of strs
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, max = 0, words, m = 0, front, back;

	while (*(str + max))
		max++;
	words = word_count(str);
	if (words == 0)
		return (NULL);
	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= max; i++)
	for (i = 0; i <= max; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (m)
			{
				back = i;
				tmp = (char *) malloc(sizeof(char) * (m + 1));
				if (tmp == NULL)
					return (NULL);
				while (front < back)
					*tmp++ = str[front++];
				*tmp = '\0';
				matrix[k] = tmp - m;
				k++;
				m = 0;
			}
		}
		else if (m++ == 0)
			front = i;
	}
	matrix[k] = NULL;
	return (matrix);
}
