#include "sort.h"

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	lomuto(array, size, 0, size - 1);
}
/**
 * lomuto - auxiliary function for the
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void lomuto(int *array, size_t size, int low, int high)
{
	int p, i, j;
	int tmp;

	if (low < high)
	{
		p = high;
		j = low;
		for (i = low; i < high; i++)
		{
			if (array[i] < array[p])
			{
				if (i != j)
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
					print_array(array, size);
				}
				j++;
			}
		}
		if (j != p && array[j] != array[p])
		{
			tmp = array[j];
			array[j] = array[p];
			array[p] = tmp;
			print_array(array, size);
		}
		lomuto(array, size, low, j - 1);
		lomuto(array, size, j + 1, high);
	}
}
