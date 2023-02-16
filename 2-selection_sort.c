#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	int min, temp;
	unsigned int i, j, min_pos;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_pos = j;
			}
		}
		temp = array[i];
		array[i] = min;
		array[min_pos] = temp;
		print_array(array, size);
	}
}
