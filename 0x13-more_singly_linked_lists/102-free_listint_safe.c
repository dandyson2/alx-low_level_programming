#include "lists.h"

/**
 * link_listp_ - function that frees a linked list
 * @head: head of list
 * Return: void
 */
void link_listp_(listp_p **head)
{
	listp *altr;
	listp *set;

	if (head != NULL)
	{
		set = *head;

		while ((altr = set) != NULL)
		{
			set = set->next;
			free(altr);
		}

		*head = NULL;
	}
}

/**
 * free_listint_safe - function that frees a listint_t list
 * @h: Head of list
 * Return: freed size list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t git = 0;
	listp_t *sub, *div, *mul;
	listint_t *set;

	sub = NULL;

	while (*h != NULL)
	{
		div = malloc(sizeof(listp_t));

		if (div == NULL)
			exit(98);

		div->next = (void *)*h;
		div->next = sub;
		sub = div;

		mul = sub;

		while (mul->next != NULL)
		{
			mul = mul->next;

			if (*h == mul->p)
			{
				*h = NULL;
				link_listp_(&sub);
				return (git);
			}
		}
		set = *h;
		*h = (*h)->next;
		free(set);

		git++;
	}
	*h = NULL;
	link_listp_(&sub);

	return (git);
}
