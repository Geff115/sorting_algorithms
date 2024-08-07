#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - This function rearrange the elements of the array
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
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, ab, i;

	pivot = array + end;
	for (ab = i = start; i < end; i++)
	{
		if (array[i] < *pivot)
		{
			if (ab < i)
			{
				swap(array + i, array + ab);
				print_array(array, size);
			}
			ab++;
		}
	}

	if (array[ab] > *pivot)
	{
		swap(array + ab, pivot);
		print_array(array, size);
	}

	return (ab);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @end: The starting index of the array partition to order.
 * @start: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int partition;

	if (end - start > 0)
	{
		partition = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, partition - 1);
		lomuto_sort(array, size, partition + 1, end);
	}
}

/**
 * quick_sort - This function uses the quick sort
 * algorithm and sorts an array recursively using the
 * Lomuto's partitioning function I created above.
 * @array: An array of elements to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
