#include "singly.h"

/**
 * free_listint2 - function that frees a listint_t list
 * @head: prr to head
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *altr;

	if (head == NULL)
	return;

	while (*head)
	{
		altr = *head;
		*head = (*head)->next;
		free(altr);
	}

head = NULL;
}
