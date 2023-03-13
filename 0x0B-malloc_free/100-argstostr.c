#include "main.h"
#include <stdlib.h>
/**
 * argstostr - function that concatenates all the arguments of your program
 * @ac: argument count
 * @av: ptr to array
 * Return: NULL if ac == 0 or av == null, ptr to new str
 * NULL if failed
 */
char *argstostr(int ac, char **av)
{
	int x, y, z, size;
	char *arg;

	size = 0;
	z = 0;
	if (ac == 0 || av == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		y = 0;
		while (av[x][y])
		{
			size++;
			y++;
		}
		size++;
		x++;
	}
	arg = malloc((sizeof(char) * size) + 1);
	if (arg == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		y = 0;
		while (av[x][y])
		{
			arg[z] = av[x][y];
			y++;
			z++;
		}
		arg[z] = '\n';
		z++;
		x++;
	}
	arg[z] = '\0';
	return (arg);
}
