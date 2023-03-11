#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that prints all arguments it receives
 * @argc: argument number
 * @argv: argument array
 * Return:0 Always
 */
int main(int argc, char *argv[])
{
	int n;

	for (n = 0; n < argc; n++)
	{
		printf("%s\n", argv[n]);
	}
	return (0);
}
