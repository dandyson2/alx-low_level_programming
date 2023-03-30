#include "lists.h"
/**
 * print_list - prints all the elements of a list_t list.
 * @h: singly linked list.
 * Return: number of elements in the list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t print_list(const list_t *h)
{
	size_t _print;

	_print = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		_print++;
	}
	return (_print);
}
