#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	aux_node = (*list)->next;
	while (aux_node != NULL)
	{
		next_swap = aux_node->next;
		while (aux_node->prev != NULL && aux_node->prev->n > aux_node->n)
		{
			aux_node->prev->next = aux_node->next;
			if (aux_node->next != NULL)
				aux_node->next->prev = aux_node->prev;
			aux_node->next = aux_node->prev;
			aux_node->prev = aux_node->next->prev;
			aux_node->next->prev = aux_node;
			if (aux_node->prev == NULL)
				*list = aux_node;
			else
				aux_node->prev->next = aux_node;
			print_list(*list);
		}
		aux_node = next_swap;
	}
}
