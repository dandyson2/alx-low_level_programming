#include "lists.h"

/**
 * add_dnodeint_end - Function that add a new node
 * at the end of a dlistint_t list
 * @head: List head
 * @n: Element value
 * Return: Address of the new element,
 * NULL if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	h = *head;

	if (h != NULL)
	{
		for (; h->next != NULL; h = h->next)
			;

			h->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = h;

	return (new);
}
