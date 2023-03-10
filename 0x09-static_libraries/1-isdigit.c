#include "main.h"

/**
 * _isdigit - check if numbers are from 0 - 9
 * @d: character to check
 * Return: 0 or 1
 */
int _isdigit(int d)
{
if (d >= '0' && d <= '9')
return (1);
else
return (0);
}
