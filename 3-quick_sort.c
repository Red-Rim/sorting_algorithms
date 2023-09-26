#include "sort.h"

/**
 * swap - swaps two integers
 * @a: the first integer
 * @b: the secd integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * the_partition - partition for Quick sort
 * @array: array
 * @beginning: starting index
 * @end: ending index
 * @size: size
 * Return: index
 */
int the_partition(int *array, int beginning, int end, size_t size)
{
	int pivot = array[end];
	int i = beginning - 1, j;

	for (j = beginning; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_recursive - recursive function for suick sort
 * @array: array
 * @beginning: starting index
 * @end: ending index
 * @size: Size of the array
 */
void quick_recursive(int *array, int beginning, int end, size_t size)
{
	int pivot;

	if (beginning < end)
	{
		pivot = the_partition(array, beginning, end, size);
		quick_recursive(array, beginning, pivot - 1, size);
		quick_recursive(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers using quick sort
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_recursive(array, 0, size - 1, size);
}