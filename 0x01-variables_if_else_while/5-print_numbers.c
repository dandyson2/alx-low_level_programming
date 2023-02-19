#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * main - Entry point
 * Task: Displays all single digit number of base 10
 * beginning from 0, followed by new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = '0';

	while (c <= '9')
	{
		putchar(c);
		c++
	}
	putchar('\n');
	return (0);
}
