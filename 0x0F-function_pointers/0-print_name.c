#include <stdio.h>
#include <stdlib.h>
/**
 * print_name - function that prints a name
 * @name: ptr to name
 * @f: function ptr
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
