#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - It sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 *
 * @list: A double Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node != NULL)
	{
		listint_t *temp_node = current_node->next;

		/* we are comparing the values between current node and previous node*/
		while (current_node->prev != NULL && current_node->n < current_node->prev->n)
		{
			/* Swap current_node and current_node->prev */
			current_node->prev->next = current_node->next;

			if (current_node->next != NULL)

				current_node->next->prev = current_node->prev;

			current_node->next = current_node->prev;

			current_node->prev = current_node->prev->prev;

			current_node->next->prev = current_node;

			if (current_node->prev != NULL)

				current_node->prev->next = current_node;
			else
				*list = current_node;

			print_list(*list);
		}

		current_node = temp_node;
	}
}
