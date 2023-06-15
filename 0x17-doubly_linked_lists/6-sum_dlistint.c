#include "lists.h"

/**
 * sum_dlistint - Function that returns sum of all
 * the data (n) of a dlistint_t linked list
 * @head: List head
 * Return: Sum of data, 0 if list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		for (; head != NULL; head = head->next)
		{
			sum += head->n;
		}
	}

	return (sum);
}
