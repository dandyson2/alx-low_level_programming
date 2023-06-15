#include "lists.h"

/**
 * add_dnodeint - Function that add a new node at
 * the begginning of a dlistint_t list
 * @head: List head
 * @n: Element value
 * Return: Address of new element, NULL if failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *h;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		for (; h->prev != NULL; h = h->prev)
			;
	}

	new->next = h;

	if (h != NULL)
		h->prev = new;

	*head = new;

	return (new);
}
