#include "main.h"
/**
 * _strspn - function that gets the length of a prefix substring
 * @s: input
 * @accept: input
 * Return 0 always (Success)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int y = 0;
	int z;

	while (*s)
	{
		for (z = 0; accept[z]; z++)
		{
			if (*s == accept[z])
			{
				y++;
				break;
			}
			else if (accept[z + 1] == '\0')
				return (y);
		}
		s++;
	}
	return (y);
}
