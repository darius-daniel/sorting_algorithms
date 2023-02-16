#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * using the Insertion sort algorithm
 *
 * @list: the linked list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node_x, *node_y;

	current = *list;
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			node_x = current;
			current = node_y = current->next;
			while (node_x != NULL && node_x->n > node_y->n)
			{
				if (node_x->prev == NULL)
					node_y->prev = NULL;
				else
					node_y->prev = node_x->prev;

				if (node_y->next == NULL)
					node_x->next = NULL;
				else
					node_x->next = node_y->next;

				if (node_x->prev != NULL)
					node_x->prev->next = node_y;
				if (node_y->next != NULL)
					node_y->next->prev = node_x;

				node_x->prev = node_y;
				node_y->next = node_x;
				if (node_x == *list)
					*list = node_y;

				node_x = node_y->prev;
				print_list(*list);
			}
		}
		else
			current = current->next;
	}
}
