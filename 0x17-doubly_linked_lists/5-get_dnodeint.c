#include "lists.h"

/**
 * get_dnodeint_at_index - Function that returns
 * the nth node of a dlistint_t linked list
 * @head: List head
 * @index: Nnt node index
 * Return: Nnt node, NULL if not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	for (unsigned int y = 0; head != NULL; head = head->next, y++)
	{
		if (y == index)
			return (head);
	}

	return (NULL);
}
