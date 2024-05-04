#include "sort.h"

/**
 * Knuth_sequence_calculation - This function generates the Knuth
 * sequence interval based on the size of the array.
 * @size: The size of the array.
 * @num_elements: Number of elements in the array.
 *
 * Return: An array containing the intervals to be used in the shell
 * sort algorithm.
 */
int *Knuth_sequence_calculation(size_t size, int *num_elements)
{
	int *sequence;
	size_t i, interval = 1;

	*num_elements = 0;
	while (interval < size)
	{
		interval = interval * 3 + 1;
		(*num_elements)++;
	}
	sequence = malloc(sizeof(int) * (*num_elements));
	if (sequence == NULL)
	{
		fprintf(stderr, "Error allocating memory for the sequence\n");
		return (NULL);
	}
	i = *num_elements - 1;
	interval = 1;
	while (interval < size)
	{
		sequence[i] = interval;
		interval = interval * 3 + 1;
		if (interval >= size)
			break;
		i--;
	}
	sequence[i] = 1;
	return (sequence);
}

/**
 * shell_insertion_sort - This function implements the insertion sort algorithm
 * in an unsorted array using a gap index.
 * @array: Array of elements.
 * @size: Size of the array.
 * @gap: gap element in a certain index from the next element's index.
 *
 */
void shell_insertion_sort(int *array, size_t size, int gap)
{
	int curr_elem, curr_idx;
	size_t i = 0;

	while (i < size)
	{
		curr_idx = i;
		curr_elem = array[i];
		while ((curr_idx >= gap) && (array[curr_idx - gap] > curr_elem))
		{
			array[curr_idx] = array[curr_idx - gap];
			curr_idx -= gap;
		}
		array[curr_idx] = curr_elem;
		i++;
	}
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
	int *Knuth_sequence, i, num_elements;

	Knuth_sequence = Knuth_sequence_calculation(size, &num_elements);
	for (i = num_elements - 1; i >= 0; i--)
	{
		shell_insertion_sort(array, size, Knuth_sequence[i]);
		print_array(array, size);
	}
	free(Knuth_sequence);
}
