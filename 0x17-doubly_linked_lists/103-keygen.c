#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * num4 - Largest number
 * @keygen: Username
 * @enth: The length of username
 * Return: Largest number
 */
int num4(char *keygen, int enth)
{
	int key;
	int gen;
	unsigned int var_num;

	key = *keygen;
	gen = 0;

	while (gen < enth)
	{
		if (key < keygen[gen])
			key = keygen[gen];
		gen += 1;
	}

	srand(key ^ 14);
	var_num = rand();

	return (var_num & 63);
}

/**
 * num5 - Char multiplier
 * @keygen: Username
 * @enth: The length of username
 * Return: The char multiplied
 */

int num5(char *keygen, int enth)
{
	int key;
	int gen;

	key = gen = 0;

	while (gen < enth)
	{
		key = key + keygen[gen] * keygen[gen];
		gen += 1;
	}

	return (((unsigned int)key ^ 239) & 63);
}

/**
 * num6 - Random char generator
 * @keygen: The username
 * Return: Random char
 */

int num6(char *keygen)
{
	int key;
	int gen;

	key = gen = 0;

	while (gen < *keygen)
	{
		key = rand();
		gen += 1;
	}

	return (((unsigned int)key ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @ac: Arg count
 * @av: Arg vector
 * Return: 0 always
 */

int main(int ac, char **av)
{
	char _keygen[7];
	int enth, key, gen;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) ac;

	for (enth = 0; av[1][enth]; enth++)
		;

	_keygen[0] = ((char *)alph)[(enth ^ 59) & 63];

	key = gen = 0;
	while (gen < enth)
	{
		key = key + av[1][gen];
		gen = gen + 1;
	}
	_keygen[1] = ((char *)alph)[(key ^ 79) & 63];

	key = 1;
	gen = 0;
	while (gen < enth)
	{
		key = av[1][gen] * key;
		gen = gen + 1;
	}
	_keygen[2] = ((char *)alph)[(key ^ 85) & 63];

	_keygen[3] = ((char *)alph)[num4(av[1], enth)];

	_keygen[4] = ((char *)alph)[num5(av[1], enth)];

	_keygen[5] = ((char *)alph)[num6(av[1])];
	_keygen[6] = '\0';
	for (key = 0; _keygen[key]; key++)
		printf("%c", _keygen[key]);
	return (0);
}
