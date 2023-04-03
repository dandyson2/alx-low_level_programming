#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node
 * of a listint_t linked list
 * @head: ptr to head
 * @index: index of node
 * Return: prt to select node, NULL if not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t tidr;

	for (tidr = 0; (tidr < index) && (head->next); tidr++)
		head = head->next;

	if (tidr < index)
	return (NULL);

	return (head);
}
