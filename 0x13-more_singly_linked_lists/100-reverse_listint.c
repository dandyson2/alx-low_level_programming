#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list
 * @head: Head of list
 * Return: prt to first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *y;
	listint_t *z;

	y = NULL;
	z = NULL;

	while (*head != NULL)
	{
		z = (*head)->next;
		(*head)->next = y;
		y = *head;
		*head = z;
	}
	*head = y;

	return (*head);
}
