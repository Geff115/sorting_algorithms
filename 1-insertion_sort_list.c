#include "sort.h"

/**
 * insertion_sort_list - This function implements the insertion sort
 * algorithm to sort an array.
 * @list: Elements in the array to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node1, *node2, *temp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	node1 = *list;
	node2 = (*list)->next;
	temp = node1;
	while (node2 != NULL)
	{
		if (node2->n < node1->n)
		{
			if (node2->prev != NULL)
				node2->prev->next = node2->next;
			if (node2->next != NULL)
				node2->next->prev = node2->prev;
			if (node2->n < (*list)->n)
			{
				node2->next = *list;
				(*list)->prev = node2;
				*list = node2;
			}
			else
			{
				while (temp->prev != NULL && temp->prev->n > node2->n)
				{
					if (temp->n <= node2->n || temp == *list)
					{
						node2->prev = temp;
						node2->next = temp->next;
						temp->next = node2;
						if (node2->next != NULL)
						{
							node2->next->prev = node2;
						}
					}
					print_list(*list);
				}
			}
		}
	}
}
