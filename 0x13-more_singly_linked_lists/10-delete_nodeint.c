#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node
 * at index index of a listint_t linked list
 * @head: ptr to head
 * @index: index of node to delete
 * Return: 1 if success, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *xax, *faax = *head;
	unsigned int v;

	if (faax == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(faax);

		return (1);
	}
	for (v = 0; v < (index - 1); v++)
	{
		if (faax->next == NULL)
			return (-1);

		faax = faax->next;
	}
	xax = faxx->next;
	faax->next = xax->next;
	free(xax);

	return (1);
}
