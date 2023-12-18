#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @start: Start index of the partition
 * @end: End index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	if (start < end)
	{
		int pivot_idx = lomuto_partition(array, start, end, size);

		quick_sort_recursive(array, start, pivot_idx - 1, size);
		quick_sort_recursive(array, pivot_idx + 1, end, size);
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @start: Start index of the partition
 * @end: End index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1;
	int j;
	int temp;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	if (i + 1 != end)
		print_array(array, size);

	return (i + 1);
}
