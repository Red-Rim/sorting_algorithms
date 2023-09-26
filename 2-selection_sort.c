#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * the Selection sort algorithm
 * @array: array
 * @size: size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{

	size_t i, j;
	int min, tmp, flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		min = i;

	for (j = i + 1; j < size; j++)
	{
		if (array[j] < array[min])
		{	min = j;
			flag = 1;
		}
	}

		{
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		if (flag)
		print_array(array, size);
		}
	}
}