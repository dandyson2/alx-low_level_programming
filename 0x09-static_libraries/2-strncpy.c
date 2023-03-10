#include "main.h"
/**
 * _strncpy -  a function that copies a string
 * @dest: value
 * @src: value
 * @n: value
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int z;

z = 0;
while (z < n && src[z] != '\0')
{
dest[z] = src[z];
z++;
}

while (z < n)
{
dest[z] = '\0';
z++;
}

return (dest);
}
