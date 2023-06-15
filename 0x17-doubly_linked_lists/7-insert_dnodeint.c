#include "lists.h"

/**
 * insert_dnodeint_at_index - Function that insert
 * a new node
 * @h: List head
 * @idx: New node index
 * @n: New node value
 * Return: Address of new node, NULL if failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	if (idx == 0)
		return (add_dnodeint(h, n));

	dlistint_t *current = *h;
	unsigned int i = 0;

	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (NULL);

	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;

	if (current->next != NULL)
		current->next->prev = new_node;

	current->next = new_node;

	return (new_node);
}
