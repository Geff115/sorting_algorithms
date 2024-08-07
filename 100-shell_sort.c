#include "sort.h"

/**
 * swap - This function swaps the nodes of two elements.
 * @a: Element to be swapped.
 * @b: Element to be swapped.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - This function uses the Knuth sequence function and the
 * shell insertion sort function optimally to implement the shell sort
 * algorithm on an array of unsorted elements.
 * @array: The array of elements to be sorted.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	/*Calculate the initial gap using the Knuth sequence*/
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/*Reduce the gap size using the Knuth sequence*/
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
