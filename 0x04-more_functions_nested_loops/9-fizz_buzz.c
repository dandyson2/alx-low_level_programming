#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the numbers from 1 to 100
 * multiples of three print Fizz
 * multiples of five print Buzz
 * multiples of both three and five print FizzBuzz
 * Return: 0 Always
 */
int main(void)
{
int x;
char a[] = "Fizz";
char b[] = "Buzz";
char cd[] = "FizzBuzz";

for (x = 1; x <= 100; x++)
{
if (x == 100)
printf("%s", b);
else if ((x % 3 == 0) && (x % 5 == 0))
printf("%s ", ab);
else if (x % 5 == 0)
printf("%s ", b);
else
printf("%d ", x);
}
printf("\n");
return (0);
}
