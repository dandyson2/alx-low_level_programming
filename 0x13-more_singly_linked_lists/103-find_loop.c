#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: ptr to head of linked list
 * Return: Address of node where loop starts, NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *add1, *add2;

	if (head == NULL || head->next == NULL)
		return (NULL);

	add1 = head->next;
	add2 = (head->next)->next;

	while (add2)
	{
		if (add1 == add2)
		{
			add1 = head;

			while (add1 != add2)
			{
				add1 = add1->next;
				add2 = add2->next;
			}
			return (add1);
		}
		add1 = add1->next;
		add2 = (add2->next)->next;
	}
	return (NULL);
}
