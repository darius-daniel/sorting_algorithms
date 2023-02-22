#include "sort.h"

/**
 * merge_sort - sorts the elements of an array in ascending order using the
 * Merger sort algorithm
 *
 * @array: the array to be sorted
 * @size: the number of elements in @array
 *
 * Return: Nothing
*/
void merge_sort(int *array, size_t size)
{
	(void)array;
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
