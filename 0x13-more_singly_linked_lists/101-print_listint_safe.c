#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * link_listp - free linked list
 * @head: Head of list
 * Return: void
 */
void link_listp(listp_t **head)
{
	listp_t *altr;
	listp_t *set;

	if (head != NULL)
	{
		set = *head;
		while ((altr = set) != NULL)
		{
			set = set->next;
			free(altr);
		}

		*head = NULL;
	}
}


/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: Head of list
 * Return: Nodes number in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t git = 0;
	listp_t *sub, *div, *mul;

	sub = NULL;
	while (head != NULL)
	{
		div = malloc(sizeof(listp_t));

		if (div == NULL)
			exit(98);

		div->p = (void *)head;
		div->next = sub;
		sub = div;

		mul = sub;

		while (mul->next != NULL)
		{
			mul = mul->next;
			if (head == mul->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				link_listp(&sub);
				return (git);
			}
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		git++;
}
link_listp(&sub);
return (git);
}
