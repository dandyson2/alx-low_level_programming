#include <stdio.h>
/**
 * main - main block
 * Task: Acquire a random number and check if it
 * is correct
 * Return: Alwaya 0 (Success)
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		if (c != 'e' && c != 'q')
		{
			putchar(c);
		}
		c++;
	}
	putchar('\n');
	return (0);
}
