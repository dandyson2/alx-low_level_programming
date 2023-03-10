#include "main.h"
/**
 * _memcpy - a function that copies memory area
 * @dest: stored memory position
 * @src: memory where it is copied
 * @n: bytes number
 * Return: copied memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
int y = 0;
int z = n;

for (y = 0;  y < z; y++)
{
dest[y] = src[y];
n--;
}

return (dest);
}
