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
	int i, res;

	res = -1;
	if (array && cmp)
	{
		if (size <= 0)
		{
			return (res);
		}
		for (i = 0; i < size; i++)
		{
			cmp(array[i]);
			if (cmp(array[i]) > 0)
			{
				res = 1;
				break;
			}
			if ((cmp(array[i]) == (-1)))
			{
				return (res);
			}
		}
	}
	return (res);
}
