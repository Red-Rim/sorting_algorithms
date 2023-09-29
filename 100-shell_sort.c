#include "sort.h"

/**
 * shell_sort - function sorts an array in ascending order in Shell sort
 * @array: array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}

	gap = (gap - 1) / 3;

	while (gap > 0)
	{
	size_t i;

	for (i = gap; i < size; i += 1)
	{
		int tmp = array[i];
		size_t j;

		for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
		{
			array[j] = array[j - gap];
		}

		array[j] = tmp;
	}

	gap /= 3;
	print_array(array, size);
	}
}
