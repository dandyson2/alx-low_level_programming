#include "main.h"
/**
 * _strstr - function that locates a substring
 * @needle: input
 * @haystack: input
 * Return: 0 Always
 */
char *_strstr(char *haystack, char *needle)
{
for (; *haystack != '\0'; haystack++)
{
char *u = haystack;
char *v = needle;

while (*u == *v && *u != '\0')
{
u++;
v++;
}
if (*v == '\0')
return (haystack);
}
return (0);
}
