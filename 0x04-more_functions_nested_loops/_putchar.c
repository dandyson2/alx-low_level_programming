#include "main.h"
#include <unistd.h>
/**
 * _putchar - displays the character c to stdout
 * @c: The character to check
 * Return: On success 1
 * on error, -1 is returned, and errno is set appropriely
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
