#include "lists.h"

/**
 * add_nodeint_end - function that adds a new
 * node at the end of a listint_t list.
 * @head: ptr to head list
 * @n: content number to use
 * Return: newly added node address
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *n_node;
	listint_t *_pointer = *head;

	n_node = malloc(sizeof(listint_t));
	if (n_node != NULL)
	{
		n_node->n = n;
		n_node->next = NULL;
	}
	else
		return (NULL);

	if (_pointer != NULL)
	{
		while (_pointer->next != NULL)
			_pointer = _pointer->next;
		_pointer->next = n_node;
	}
	else
		*head = n_node;

	return (n_node);
}
