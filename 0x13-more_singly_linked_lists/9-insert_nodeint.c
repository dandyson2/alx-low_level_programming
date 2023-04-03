#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node
 * at a given position
 * at a given position.
 * @head: ptr to head
 * @idx: index of list where new node is added
 * @n: value for new node to add
 * Return: ptr to new node, NULL if function fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *max, *altr = *head;
	unsigned int v;

	max = malloc(sizeof(listint_t));

	if (max == NULL)
	return (NULL);

	max->n = n;

	if (idx == 0)
	{
		max->next = altr;
		*head = max;

		return (max);
	}
	for (v = 0; v < (idx - 1); v++)
	{
		if (altr == NULL || altr->next == NULL)
			return (NULL);

		altr = altr->next;
	}
	max->next = altr->next;
	altr->next = max;

	return (max);
}
