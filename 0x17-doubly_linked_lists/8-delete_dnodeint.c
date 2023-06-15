#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *module1;
	dlistint_t *module2;
	unsigned int y;

	module1 = *head;

	if (module1 != NULL)
		while (module1->prev != NULL)
			module1 = module1->prev;

	y = 0;

	while (module1 != NULL)
	{
		if (y == index)
		{
			if (y == 0)
			{
				*head = module1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}

			else
			{
				module2->next = module1->next;

				if (module1->next != NULL)
					module1->next->prev = module2;
			}

			free(module1)

			return (1);
		}

		module2 = module1;
		module1 = module1->next;

		y++;
	}

	return (-1);
}
