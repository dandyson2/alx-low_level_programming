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
	dlistint_t *new_node;
	dlistint_t *base;
	unsigned int y;

	new_node = NULL;
	if (idx == 0)
		new_node = add_dnodeint(h, n);
	else
	{
		base = *h;
		y = 1;
		if (base != NULL)
			while (base->prev != NULL)
				base = base->prev;
		while (base != NULL)
		{
			if (y == idx)
			{
				if (base->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->n = n;
						new_node->next = base->next;
						new_node->prev = base;
						base->next->prev = new_node;
						base->next = new_node;
					}
				}
				break;
			}
			base = base->next;
			y++;
		}
	}

	return (new_node);
}
