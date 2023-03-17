#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <limits.h>

/**
 * main - multiplies two positive numbers
 * @argc: n arguments
 * @argv: arguments
 * Return: int
 */
int main(int argc, char *argv[])
{
	unsigned long mul;
	int y, z;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (y = 1; y < argc; y++)
	{
		for (z = 0; argv[y][z] != '\0'; z++)
		{
			if (argv[y][z] > 57 || argv[y][z] < 48)
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	mul = atol(argv[1]) * atol(argv[2]);
	printf("%lu\n", mul);
	return (0);
}
