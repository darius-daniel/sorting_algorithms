#include "sort.h"
#include <stdbool.h>

/**
 * quick_sort_hoare - sorts an array of ints using the Quick sort algorithm,
 * by utilising the Hoare partition scheme
 *
 * @array: the array to sorted
 * @size: the number of elements in @array
 *
 * Return: Nothing
*/
void quick_sort_hoare(int *array, size_t size)
{
	hoare_partition(array, size, 0, size - 1);
}

/**
 * hoare - handles partitioning and sorting of the array according to the
 * Hoare partitioning scheme
 *
 * @array: the array to be partitioned and sorted
 * @size: the number of elements in @array
 * @low: index of the left-most element in the array or subarray
 * @high: index of the right-most element in the array or subarray 
*/
void hoare_partition(int *array, size_t size, unsigned int low, unsigned int high)
{
	unsigned int l_mark, r_mark;
	bool done;
	int pivot;

	if (low < high)
	{
		done = false;
		pivot = array[high];
		l_mark = low;
		r_mark = high;
		while (!done)
		{
			while (array[l_mark] <= pivot && l_mark < r_mark)
				l_mark++;

			while (array[r_mark] >= pivot && r_mark > l_mark)
				r_mark--;

			if (l_mark >= r_mark)
				done = true;
			else if (array[l_mark] > array[r_mark])
			{
				swap(array, l_mark, r_mark);
				print_array(array, size);
			}
			else{
				l_mark++;
				r_mark--;
			}
		}
		swap(array, l_mark, high);
		print_array(array, size);

		if (l_mark > 0)
			hoare_partition(array, size, low, l_mark - 1);
		hoare_partition(array, size, l_mark + 1, high);
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
