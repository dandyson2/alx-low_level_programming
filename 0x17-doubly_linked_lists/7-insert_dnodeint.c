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
	dlistint_t *new;
	dlistint_t *head;
	unsigned int i;

	new = NULL;
	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		head = *h;
		if (head != NULL)
		{
			while (head->prev != NULL)
				head = head->prev;
		}

		for (i = 1; head != NULL && i < idx; i++)
		{
			head = head->next;
		}

		if (head != NULL && i == idx)
		{
			if (head->next == NULL)
				new = add_dnodeint_end(h, n);
			else
			{
				new = malloc(sizeof(dlistint_t));
				if (new != NULL)
				{
					new->n = n;
					new->next = head->next;
					new->prev = head;
					head->next->prev = new;
					head->next = new;
				}
			}

			break;
		}

		head = head->next;
		i++;
	}

	return (new);
}
