#include "sort.h"


void swap(int *array, unsigned int left, unsigned int right);
void lomuto(int *array, size_t size, unsigned int low, unsigned int high);

/**
 * quick_sort - sorts the elements of an array in ascending order using the
 * Quick sort algorithm that utilizes the Lomuto partition scheme
 *
 * @array: the array to be sorted
 * @size: the number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	lomuto(array, size, 0, size - 1);
}

/**
 * lomuto - helper for the quick_sort function. Splits the array
 * into subarray calling itself recursively.
 * @array: the array
 * @low: index of the first element of the sublist
 * @high:  index of the last element of the sublist
*/
void lomuto(int *array, size_t size, unsigned int low, unsigned int high)
{
	int pivot = array[high];
	unsigned int i, j;

	if (low < high)
	{
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
		swap(array, j, high);
		print_array(array, size);

		lomuto(array, size, low, i - 1);
		lomuto(array, size, j + 1, high);
	}
}

/**
 * swap - swaps two elements in an array
 * @array: the array
 * @left: the leftmost element
 * @right: the rightmost element
 * Return: Nothing
*/
void swap(int *array, unsigned int left, unsigned int right)
{
	int temp;

	temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
