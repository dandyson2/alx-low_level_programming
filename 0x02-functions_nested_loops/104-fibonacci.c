#include <stdio.h>
/**
 * main - main block
 * Task: key in and display the sum of all the multiples of 3
 * 5 below 1024 (not included), followed by a new line
 * Return: 0
 */
int main(void)
{
	unsigned long int z;
	unsigned long int bef = 1;
	unsigned long int aft = 2;
	unsigned long int l = 1000000000;
	unsigned long int bef1;
	unsigned long int bef2;
	unsigned long int aft1;
	unsigned long int aft2;

	printf("%lu", bef);

	for (z = 1; z < 91; z++)
	{
		printf(", %lu", aft);
		aft += bef;
		bef = aft - bef;
	}
	bef1 = (bef / l);
	bef2 = (bef % l);
	aft1 = (aft / l);
	aft2 = (aft % l);

	for (z = 0; z < 99; z++)
	{
		printf(", %lu", aft1 + (aft2 / l));
		printf("%lu", aft2 % 1);
		aft1 = aft1 + bef1;
		bef1 = aft1 - bef1;
		aft2 = aft2 + bef2;
		bef2 = aft2 - bef2;
	}
	printf("\n");
	return (0);
}
