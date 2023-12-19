#include "sort.h"

/**
* shell_sort - this function sorts an array in ascending order.
* @array: array to be sorted.
* @size: size of the array to be sorted.
* Return: void.
*/

void shell_sort(int *array, size_t size)
{
	size_t i;

	size_t j;

	size_t array_divided;

	size_t dif;

	int arr_ele;

	dif = 1;

	array_divided = size / 3;

	do {
		dif = dif * 3 + 1;
	} while (dif < array_divided);

	while (dif > 0)
	{
		printf("%lu", dif);

		print_array(array, size);

		for (i = dif; i < size; i++)
		{
			arr_ele = array[i];
			for (j = i; j >= dif && array[j - dif] > arr_ele; j -= dif)
			{
				array[j] = array[j - dif];
			}

			array[j] = arr_ele;
		}
	}

	dif = dif / 3;
}
