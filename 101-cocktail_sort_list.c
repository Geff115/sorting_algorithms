#include "sort.h"

/**
 * swap_node_forward - This function swaps the node of a doubly linked
 * list listint_t of integers with the node in front of it.
 * @list: A pointer to a pointer to the head of a
 * doubly linked list of integers.
 * @tail: A pointer to a pointer to the tail of a doubly linked list.
 * @shaker: A pointer to the swapping node of the
 * cocktail shaker algorithm.
 */
void swap_node_forward(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_behind - This function swaps the node of a doubly linked
 * list listint_t of integers with the node in front of it.
 * @list: A pointer to the head of a doubly linked list of integers.
 * @tail: A pointer to the tail of the doubly linked list.
 * @shaker: A pointer to the current swapping node of the
 * cocktail shaker algorithm.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - This function sorts a listint_t doubly linked
 * list of integers in ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shake_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shake_not_stirred == false)
	{
		shake_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_forward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shake_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shake_not_stirred = false;
			}
		}
	}
}
