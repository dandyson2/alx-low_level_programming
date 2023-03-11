#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that multiplies two numbers
 * @argc: argument count
 * @argv: argument array
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	int max, multiply;

	multiply = 1;
	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}
	for (max = 1; max < argc; max++)
	{
		multiply = multiply * atoi(argv[max]);
	}
	printf("%d\n", multiply);
	return (0);
}
