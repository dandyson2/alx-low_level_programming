#include "search_algos.h"

/**
* interpolation_search - searches for a value in an array of integers
* using the Interpolation search algorithm
* @array: input array
* @size: size of the array
* @value: value to search for
* Return: index of the number, or -1 if not found
*/
int interpolation_search(int *array, size_t size, int value)
{
size_t low = 0;
size_t high = size - 1;
size_t pos;
double f;

if (array == NULL)
return (-1);

while (low <= high && value >= array[low] && value <= array[high])
{
f = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
pos = (size_t)(low + f);

printf("Value checked array[%d] = [%d]\n", (int)pos, array[pos]);

if (array[pos] == value)
return ((int)pos);

if (array[pos] < value)
low = pos + 1;
else
high = pos - 1;
}

printf("Value checked array[%d] is out of range\n", (int)pos);
return (-1);
}
