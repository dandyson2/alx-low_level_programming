#include <stdio.h>

/**
 * main - print the first 98 Fibonacci numbers,
 * starting with 1 and 2, seperated by a comma
 * Return: 0
 */
int main(void)
{
	int key;
	unsigned long com1 = 0, com2 = 1, sum;
	unsigned long com1_pass1, com1_pass2, com2_pass1, com2_pass2;
	unsigned long pass1, pass2;

	for (key = 0; key < 92; key++)
	{
		sum = com1 + com2;
		printf("%lu, ", sum);
		com1 = com2;
		com2 = sum;
	}
		com1_pass1 = com1 / 10000000000;
		com2_pass1 = com2 / 10000000000;
		com1_pass2 = com1 % 10000000000;
		com2_pass2 = com2 % 10000000000;
		for (key = 90; key < 99; key++)
	{
		pass1 = com1_pass1 + com2_pass1;
		pass2 = com1_pass2 + com2_pass2;
		if (com1_pass2 + com2_pass2 > 9999999999)
	{
		pass1 += 1;
		pass2 %= 10000000000;
	}
		printf("%lu%lu", pass1, pass2);
		if (key != 98)
		printf(", ");
		com1_pass1 = com2_pass1;
		com1_pass2 = com2_pass2;
		com1_pass1 = pass1;
		com2_pass2 = pass2;
	}
		printf("\n");
		return (0);
}
