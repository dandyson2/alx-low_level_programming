#include "lists.h"

/**
 * dlistint_len - Function that returns the number
 * of elements in a linked dlistint_t list
 * @h: Lists head
 * Return: Number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	int numb;

	numb = 0;

	if (h == NULL)
		return (numb);

	for (; h->prev != NULL; h = h->prev)
		;

	for (; h != NULL; h = h->next)
		numb++;

	return (numb);
}
