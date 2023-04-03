#include "lists.h"
#include <stdio.h>

/**
 * sum_listint - function that returns the sum of all
 * the data (n) of a listint_t linked list
 * @head: ptr to head
 * Return: sum of all data, 0 if list is empty
 */
int sum_listint(listint_t *head)
{
	int _sum;

	_sum = 0;

	while (head)
	{
		_sum += head->n;
		head = head->next;
	}

	return (_sum);
}

