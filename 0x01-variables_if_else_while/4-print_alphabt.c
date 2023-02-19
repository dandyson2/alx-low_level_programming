#include <stdio.h>
/**
 * main - Displays the alphabet in lowercase,
 * followed by a new line, except q and e
 * Return: Alwaya 0 (Success)
 */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if (ch != 'e' && ch != 'q')
		{
			putchar(ch);
		}
		ch++;
	}
	putchar('\n')
	return (0);
}
