#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
* binary_search - searches for a value in an array of
* integers using the Binary search algorithm
* @array: array to search the value in
* @size: size of the array
* @value: value to look for
*
* Return: the index of the found value,
* or -1 if not found
*/
int binary_search(int *array, size_t size, int value)
{
if (!array || size == 0)
return (-1);

size_t lo = 0;
size_t hi = size - 1;

while (lo <= hi)
{
size_t mid = (lo + hi) / 2;

array_print(array, lo, hi);
if (array[mid] == value)
return (mid);
else if (array[mid] < value)
lo = mid + 1;
else
hi = mid - 1;
}

return (-1);
}

/**
* array_print - prints an array
* @array: array to print
* @lo: index of the low bound
* @hi: index of the high bound
*/
void array_print(int *array, size_t lo, size_t hi)
{
printf("Searching in array: ");
for (size_t i = lo; i <= hi; i++)
{
printf("%d", array[i]);
if (i < hi)
printf(", ");
}
printf("\n");
}

