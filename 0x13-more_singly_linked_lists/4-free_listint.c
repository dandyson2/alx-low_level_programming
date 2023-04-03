#include "singly.h"

/**
 * free_listint - function that frees a listint_t list
 * @head: The list head
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	listint_t *altr;

	while (head != NULL)
	{
		altr = head;
		head = head->next;

		free(altr);
	}
}
