#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending order
 *  using the quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	lomuto(array, size, 0, size - 1);
}
/**
 * lomuto - implementation of the lomuto partition scheme
 * @array: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: Nothing
 */
void lomuto(int *array, size_t size, int low, int high)
{
	int pivot_idx, i, j, pivot;

	if (low < high)
	{
		pivot_idx = high;
		pivot = array[pivot_idx];
		j = low;
		for (i = low; i < high; i++)
		{
			if (array[i] < pivot)
			{
				if (i != j)
				{
					swap(array, i, j);
					print_array(array, size);
				}
				j++;
			}
		}
		if (j != pivot_idx && array[j] != pivot)
		{
			swap(array, j, pivot_idx);
			print_array(array, size);
		}
		lomuto(array, size, low, j - 1);
		lomuto(array, size, j + 1, high);
	}
}

/**
 * swap - swaps two elements in of an array
 * @array: the array containing the elements to be swapped
 * @left_idx: the index of the element on the left
 * @right_idx: the index of the element on the right
 * Return: Nothing
*/
void swap(int *array, unsigned int left_idx, unsigned int right_idx)
{
	int temp;

	temp = array[left_idx];
	array[left_idx] = array[right_idx];
	array[right_idx] = temp;
}
