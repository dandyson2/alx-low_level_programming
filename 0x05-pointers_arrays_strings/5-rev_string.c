#include "main.h"
/**
 * rev_string - a function that reverses a string
 * @s: param
 */
void rev_string(char *s)
{
char tmp;
int i, max1, max2;

max1 = 0;
max2 = 0;

while (s[max1] != '\0')
max1++;

max2 = max1 - 1;
for (i = 0; i < max1 / 2; i++)
{
tmp = s[i];
s[i] = s[max2];
s[max2] = tmp;
max2 -= 1;
}
}
