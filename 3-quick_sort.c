#include "sort.h"

/**
 * swap - This function swaps two elements.
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
 * lomuto_partition: This function rearrange the elements of the array
 * so that all elements that are less than the pivot will be to the
 * right of the pivot element, and elements greater than the pivot
 * are to the left of the pivot element.
 * @array: An array of elements to be partitioned.
 * @start: The range of the sub-array to be partitioned.
 * @end: The range of the sub-array to be partitioned.
 * @size: The size of the array.
 *
 * Return: The pivot element.
 */
int lomuto_partition(int *array, int start, int end, size_t size)
{
	int i, pivot;
	(void)size;

	pivot = array[end - 1];
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			swap(&array[i], &array[start]);
			start++;
		}
	}
	swap(&array[start], &array[end - 1]);
	return (start);
}

/**
 * quick_sort: This function uses the quick sort
 * algorithm and sorts an array recursively using the
 * Lomuto's partitioning function I created above.
 * @array: An array of elements to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int pivot_index;

	if (size < 2)
		return;

	pivot_index = lomuto_partition(array, 0, size, size);
	print_array(array, size);
	quick_sort(array, pivot_index);
	quick_sort(array + pivot_index + 1, size - pivot_index - 1);
}
