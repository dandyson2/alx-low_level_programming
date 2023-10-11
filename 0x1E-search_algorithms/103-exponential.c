#include <stdio.h>
#include "search_algos.h"

int exponential_search(int *array, size_t size, int value);
int help_binary(int *array, int value, size_t lo, size_t hi);
void array_print(int *array, size_t lo, size_t hi);

/**
* exponential_search - function that searches for a value in a sorted
* array of integers using the Exponential search algorithm
* @array: The array to search the value
* @size: Size of the array
* @value: The value to search
* Return: -1 If value is not present in array or if array is NULL.
*/

int exponential_search(int *array, size_t size, int value)
{
size_t start = 1, end = 1, x;

if (!array || size == 0)
return (-1);

while (end < size)
{
if (value <= array[end])
break;

printf("Value checked array[%lu] = [%d]\n", end, array[end]);
start = end;
end *= 2;
}

x = (end < size - 1) ? end : size - 1;
printf("Value found between indexes [%lu] and [%lu]\n", start, x);

return (help_binary(array, value, end / 2, x));
}

/**
* help_binary - searches for a value in an array of
* integers using recursion
* @array: array to search the value in
* @value: value to look for
* @lo: index of the low bound
* @hi: index of the high bound
*
* Return: the index of the found value,
* or -1 if not found
*/

int help_binary(int *array, int value, size_t lo, size_t hi)
{
if (hi >= lo)
{
size_t mid = lo + (hi - lo) / 2;

array_print(array, lo, hi);

if (array[mid] == value)
return (mid);
if (array[mid] > value)
return (help_binary(array, value, lo, mid - 1));
return (help_binary(array, value, mid + 1, hi));
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
