#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - print the largest prime number
 * Return: Always
 */
int main(void)
{
long max = 612852475143, min;
while (min < (max / 2))
{
if ((max % 2) == 0)
{
max /= 2;
continue;
}
for (min = 3; min < (max / 2); min += 2)
{
if ((max % min) == 0)
max /= min;
}
}
printf("%ld\n", max);
return (0);
}
