#include <stdio.h>
/**
 * main - program that prints the number of arguments passed into it
 * @args: argument count
 * @argv: argument array
 * Return 0 Always
 */
int main(int args, char *argv[])
{
	printf("%d\n", args - 1);
	(void)argv;
	return (0);
}
