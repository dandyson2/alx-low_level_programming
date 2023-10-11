#include "search_algos.h"
#include <math.h>

/**
* jump_search - function that searches for a value in a sorted array
* using the Jump search algorithm
* @array: The array to search
* @size: Array size
* @value: The value to search for
* Return: -1 If value is not present in array or if array is NULL.
*/

int jump_search(int *array, size_t size, int value)
{
if (!array || size == 0)
return (-1);

size_t step = sqrt(size);
size_t prev = 0;
size_t curr = 0;

while (curr < size && array[curr] < value)
{
printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
prev = curr;
curr += step;
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

while (prev <= curr && prev < size)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
if (array[prev] == value)
return (prev);
prev++;
}

return (-1);
}
