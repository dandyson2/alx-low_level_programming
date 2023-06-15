#include "lists.h"

/**
 * free_dlistint - Function that frees a dlistint_t list
 * @head: List head
 * Return: Always 0
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head != NULL)
	{
		for (; head->prev != NULL; head = head->prev)
			;
	}

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
