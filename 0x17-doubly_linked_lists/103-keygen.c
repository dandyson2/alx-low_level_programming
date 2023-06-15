#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * f4 - Finds largest number
 * @usrn: Username
 * @len: Username length
 * Return: Highest number
 */

int f4(char *usrn, int len)
{
	int ch;
	int vch;

	ch = *usrn;
	vch = 0;

	while (vch < len)
	{
		if (ch < usrn[vch])
			ch = usrn[vch];
		vch += 1;
	}

	srand(ch ^ 14);
	return rand() & 63;
}

/**
 * f5 - Chae multiplier
 * @usrn: Username
 * @len: Username length
 * Return: Char
 */

int f5(char *usrn, int len)
{
	int ch;
	int vch;

	ch = vch = 0;

	while (vch < len)
	{
		ch = ch + usrn[vch] * usrn[vch];
		vch += 1;
	}

	return (ch ^ 239) & 63;
}

/**
 * f6 - Randim char generator
 * @usrn: username
 * Return: Char in random
 */

int f6(char *usrn)
{
	int ch;
	int vch;

	ch = vch = 0;

	while (vch < *usrn)
	{
		ch = rand();
		vch += 1;
	}

	return (ch ^ 229) & 63;
}

/**
 * main - Entry point
 * @argc: Arg count
 * @argv: Arg vector
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char keygen[7];
	int len, ch, vch;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	// Calculate the length of the username
	for (len = 0; argv[1][len]; len++)
		;

	/* ----------- f1 ----------- */
	keygen[0] = ((char *)alph)[(len ^ 59) & 63];

	/* ----------- f2 ----------- */
	ch = vch = 0;
	while (vch < len)
	{
		ch = ch + argv[1][vch];
		vch = vch + 1;
	}
	keygen[1] = ((char *)alph)[(ch ^ 79) & 63];

	/* ----------- f3 ----------- */
	ch = 1;
	vch = 0;
	while (vch < len)
	{
		ch = argv[1][vch] * ch;
		vch = vch + 1;
	}
	keygen[2] = ((char *)alph)[(ch ^ 85) & 63];
}	/* ----------- f4 -----------
