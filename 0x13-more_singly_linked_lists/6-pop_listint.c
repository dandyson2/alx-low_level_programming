#include "lists.h"

/**
 * pop_listint - function that deletes the head of
 * listint_t linked list, and returns the head node’s data (n).
 * @head: Node's data head
 * Return: Head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *altr;
	int n;

	altr = *head;

	if (altr == NULL)
	return (0);

	*head = altr->next;
	n = altr->n;
	free(altr);

	return (n);
}
