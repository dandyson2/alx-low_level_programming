#include "search_algos.h"
#include <math.h>

/**
* jump_search - searches for a value in a sorted array of integers
* using the Jump search algorithm
* @array: array to look into
* @size: size of the array
* @value: value to look for
*
* Return: index of the value found, or -1
*/
int jump_search(int *array, size_t size, int value)
{
if (!array || size == 0)
return (-1);

size_t step = sqrt(size);
size_t start, end;

for (start = 0, end = step; start < size; start = end, end = start + step)
{
printf("Value checked array[%lu] = [%d]\n", start, array[start]);
if (end < size)
{
if (array[start] <= value && value <= array[end])
{
printf("Value found between indexes [%lu] and [%lu]\n", start, end);
break;
}
}
else
{
if (array[start] <= value)
{
printf("Value found between indexes [%lu] and [%lu]\n", start, end);
break;
}
}
}

for (size_t i = start; i <= end && i < size; ++i)
{
printf("Value checked array[%lu] = [%d]\n", i, array[i]);
if (array[i] == value)
return (i);
}

return (-1);
}
