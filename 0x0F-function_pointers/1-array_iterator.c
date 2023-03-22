#include <stdio.h>
#include <stdlib.h>
/**
 * array_iterator - function that executes a function
 * given as a parameter on each element of an array.
 * @array: array of elements
 * @size: size of array
 * @action: function ptr
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int a;

	if (array && size > 0 && action)
	{
		for (a = 0; a < size; a++)
		{
			action(array[a]);
		}
	}
}
