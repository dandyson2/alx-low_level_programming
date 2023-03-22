#include <stdio.h>
#include <stdlib.h>
/**
 * int_index -  function that searches for an integer
 * @array: array of int
 * @size: num of elements in array
 * @cmp: ptr to function to compare values
 * Return: index of first elements
 * -1 if no element is found or siz <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int a, ele;

	ele = -1;
	if (array && cmp)
	{
		if (size <= 0)
		{
			return (ele);
		}
		for (a = 0; a < size; a++)
		{
			cmp(array[a]);
			if (cmp(array[a]) > 0)
			{
				ele = 1;
				break;
			}
			if ((cmp(array[a]) == (-1)))
			{
				return (ele);
			}
		}
	}
	return (ele);
}
