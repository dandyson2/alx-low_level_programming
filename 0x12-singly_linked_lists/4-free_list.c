#include "lists.h"

/**
 * free_list - function that frees a list_t list.
 * @head: head of the linked list.
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *start_node;

	while ((start_node = head) != NULL)
	{
		head = head->next;
		free(start_node->str);
		free(start_node);
	}
}
