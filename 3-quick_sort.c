#include "sort.h"

/**
 * swpints - swaps two ints
 * @num1: pointer to int 1
 * @num2: pointer to int 2
 * Return: void
 */
void swpints(int *num1, int *num2)
{
	int holdInt;

	holdInt = *num1;
	*num1 = *num2;
	*num2 = holdInt;
}

/**
 * l_partition - Lomuto partition scheme
 * @arr: integer array to sort
 * @size: size of the array
 * @high: high value
 * @low: low value
 * Return: void
 */
int l_partition(int arr[], int low, int high, size_t size)
{
	int *pivot;
	int i, j;

	pivot = &arr[high];
	for (i = j = low; j < high; j++)
	{
		if (arr[j] < *pivot)
		{
			if (i < j)
			{
				swpints(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] > *pivot)
	{
		swpints(&arr[i], pivot);
		print_array(arr, size);
	}
	return (i);
}

/**
 * quick_sort - time comp eff arr sort algo
 * @array: integer array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int x = 0, y = (size - 1);

	if (!array || size < 2)
		return;
	l_cycler(array, size, x, y);
}

/**
 * l_cycler - recursive cycler for qsort algo
 * @array: integer array to sort
 * @size: size of the array
 * @x: starting value
 * @y: secondary value
 * Return: void
 */
void l_cycler(int *array, size_t size, int x, int y)
{
	int p;

	if ((y - x) > 0)
	{
		p = l_partition(array, x, y, size);
		l_cycler(array, size, x, (p - 1));
		l_cycler(array, size, (p + 1), y);
	}
}
