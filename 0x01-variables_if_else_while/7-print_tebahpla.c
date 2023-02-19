#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - main point
 * Task: Displays all single digit number of base 10
 * beginning from 0, followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
