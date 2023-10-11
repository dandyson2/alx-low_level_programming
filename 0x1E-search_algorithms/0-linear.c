#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* linear_search - function that searches for a
* value in an array of integers using the Linear search algorithm
* @array: Array to search the value in
* @size: Array size
* @value: value to search for
* Return: -1 If value is not present in array or if array is NULL.
*/

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array || size == 0)
		return (-1);

	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}

	return (-1);
}
