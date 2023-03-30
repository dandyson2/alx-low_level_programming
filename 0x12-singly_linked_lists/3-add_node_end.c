#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of the head.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end_node, *start_node;
	size_t h;

	end_node = malloc(sizeof(list_t));
	if (end_node == NULL)
		return (NULL);

	end_node->str = strdup(str);

	for (h = 0; str[h]; h++)
		;

	end_node->len = h;
	end_node->next = NULL;
	start_node = *head;

	if (start_node == NULL)
	{
		*head = end_node;
	}
	else
	{
		while (start_node->next != NULL)
			start_node = start_node->next;
		start_node->next = end_node;
	}

	return (*head);
}
