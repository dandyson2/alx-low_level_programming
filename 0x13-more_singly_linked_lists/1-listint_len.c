#include "singly.h"

/**
 * listint_len - function that returns the number
 * of elements in a linked listint_t list.
 * @h: Head
 * Return: elements number
 */
size_t listint_len(const listint_t *h)
{
	const listint_t  *_pointer = h;
	size_t num = 0;

	while (_pointer != NULL)
	{
		num += 1;
		_pointer = _pointer->next;
	}
	return (num);
}
