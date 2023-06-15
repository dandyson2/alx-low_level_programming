#include "lists.h"

/**
 * print_dlistint - Function that prints all the
 * elements of a dlistint_t list
 * @h: Lists head
 * Return: Number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int numb;

	numb = 0;

	if (h == NULL)
		return (numb);

	for (; h->prev != NULL; h = h->prev)
	{

	}

	while (h != NULL)
	{
		printf("%d\n", h->n);
		numb++;
		h = h->next;
	}

	return (numb);
}
