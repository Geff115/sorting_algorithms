#include "sort.h"

/**
 * swap_nodes - This function swaps the nodes in a list.
 * @list: Elements in the array to be sorted.
 * @node1: first node in the list.
 * @node2: second node in the list.
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - This function uses the insertion sort algorithm
 * to sort a list.
 * @list: The elements to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node1, *node2, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	for (node1 = (*list)->next; node1 != NULL; node1 = tmp)
	{
		tmp = node1->next;
		node2 = node1->prev;
		while (node2 != NULL && node1->n < node2->n)
		{
			swap_nodes(list, &node2, node1);
			print_list((const listint_t *)*list);
		}
	}
}
