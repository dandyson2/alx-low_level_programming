#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * main -  program that adds positive numbers
 * @argc: argument count
 * @argv: argument array
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	int num = 0, c;

	if (argc > 1)
	{
		for (c = 1; c < argc; c++)
		{
			int b;
			char *str;

			str = argv[c];
			for (b = 0; str[b] != '\0'; b++)
			{
				if (str[b] < 48 || str[b] > 57)
				{
					printf("Error\n");
					return (1);
				}
			}
		}
	}
	for (c = 1; c < argc; c++)
	{
		num += atoi(argv[c]);
	}
	printf("%d\n", num);
	return (0);
}
