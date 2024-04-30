#include "sort.h"

/**
 * swap_nodes - This function swaps the nodes in a list.
 * @list: Elements in the array to be sorted.
 * @node1: first node in the list.
 * @node2: second node in the list.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *tmp_prev, *tmp_next;

	if (list == NULL || *list == NULL || node1 == NULL || node2 == NULL)
	{
		return;
	}
	if (node1->next != NULL)
		node1->next->prev = node2;
	if (node2->prev != NULL)
		node2->prev->next = node1;
	tmp_next = node1->next;
	tmp_prev = node1->prev;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = tmp_next;
	node2->prev = tmp_prev;
	if (tmp_next != NULL)
		tmp_next->prev = node1;
	if (tmp_prev != NULL)
		tmp_prev->next = node2;
	if (node1 == *list)
		*list = node2;
}

/**
 * insertion_sort_list - This function uses the insertion sort algorithm
 * to sort a list.
 * @list: The elements to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node1, *node2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node2 = (*list)->next;
	while (node2 != NULL)
	{
		node1 = node2->prev;
		while (node1 != NULL && node2->n < node1->n)
		{
			swap_nodes(list, node2, node1);
			print_list(*list);
			node2 = node1;
			node1 = node2->prev;
		}
		node2 = node2->next;
	}
}
