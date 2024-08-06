#include "sort.h"
#include <stdio.h>

/**
 * swap_int - Swap two integers in an array
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
* selection_sort - sorts an array of ints in ascending order
* using Selection sort algorithm
* @array: array to be sorted.
* @size: size of array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_index;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = array + i;
		for (j = i + 1; j < size; j++)
			min_index = (array[j] < *min_index) ? (array + j) : min_index;
		if ((array + i) != min_index)
		{
			swap_int(array + i, min_index);
			print_array(array, size);
		}
	}
}
