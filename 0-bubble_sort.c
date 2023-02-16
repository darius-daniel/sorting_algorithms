#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: number of elements in the array
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int start_idx, last_idx, swap;
	int temp;

	swap = 1;
	for (last_idx = size - 1; last_idx > 0 && swap == 1; last_idx--)
	{
		swap = 0;
		for (start_idx = 0; start_idx < last_idx; start_idx++)
		{
			if (array[start_idx] > array[start_idx + 1])
			{
				temp = array[start_idx];
				array[start_idx] = array[start_idx + 1];
				array[start_idx + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
