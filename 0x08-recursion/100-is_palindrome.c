#include "main.h"
/**
 * max - evaluate the length of a string
 * @s: input
 * Return: the length of string
 */
int max(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + max(s + 1));
}

/**
 * _preview - evaluate if the string is palindrome
 * @x: index
 * @len: length of the string
 * @s: thr string
 * Return: 1 if palindrome, 0 if not
 */
int _preview(int x, int len, char *s)
{
	if (len > 0)
	{
		if (s[x] == s[len])
		{
			return (_preview(x + 1, len - 1, s));
		}
		else if (s[x] != s[len])
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (1);
}

/**
 * is_palindrome - func that returns 1 if a str is a palindrome and 0 if not
 * @s: str
 * Return: return 1 if str is palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	return (_preview(0, max(s) - 1, s));
}
