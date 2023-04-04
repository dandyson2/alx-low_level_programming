#include "lists.h"

/**
 * link_listx - free linked list
 * @head: Head of list
 * Return: void
 */
void link_listx(listx_t **head)
{
	listx_t *altr;
	listx_t *set;

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
	listx_t *sub, *div, *mul;

	sub = NULL;
	while (head != NULL)
	{
		div = malloc(sizeof(listx_t));

		if (div == NULL)
			exit(98);

		div->x = (void *)head;
		div->next = sub;
		sub = div;

		mul = sub;

		while (mul->next != NULL)
		{
			mul = mul->next;
			if (head == mul->x)
			{
				printf("-> [%x] %d\n", (void *)head, head->n);
				head = head->next;
				git++;
}
link_listx(&sub);
return (git);
}
