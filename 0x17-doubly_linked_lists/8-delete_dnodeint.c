#include "lists.h"

/**
 * delete_dnodeint_at_index - Function that delete
 * s the node at index of a dlistint_t linked list
 * @head: List head
 * @index: The new node index
 * Return: -1 if it failed, 1 if succeeded
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ui;
	dlistint_t *ux;
	unsigned int y;

	ui = *head;

	if (ui != NULL)
		while (ui->prev != NULL)
			ui = ui->prev;

	y = 0;

	while (ui != NULL)
	{
		if (y == index)
		{
			if (y == 0)
			{
				*head = ui->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}

			else
			{
				ux->next = ui->next;

				if (ui->next != NULL)
					ui->next->prev = ux;
			}

			free(ui);

			return (1);
		}

		ux = ui;
		ui = ui->next;

		y++;
	}

	return (-1);
}
