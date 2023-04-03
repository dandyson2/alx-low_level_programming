#include "singly.h"

/**
 * print_listint - function that prints all the elements of a listint_t list.
 * @h: head of list
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t = *_pointer = h;
	size_t number = 0;

	while (_pointer != NULL)
	{
		printf("%d\n", _pointer->n);
		number += 1;
		_pointer = _pointer->next;
	}
	return (number);
}
