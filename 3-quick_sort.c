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
 * partition - Lomuto partition scheme
 * @arr: integer array to sort
 * @size: size of the array
 * @high: high value
 * @low: low value
 * Return: void
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot;
	int i;

	i = (low - 1);
	pivot = arr[high];
	for (int j = low; j <= (high - 1); j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swpints(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	swpints(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
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
	cycler(array, size, x, y);
}

/**
 * cycler - recursive cycler for qsort algo
 * @array: integer array to sort
 * @size: size of the array
 * @x: starting value
 * @y: secondary value
 * Return: void
 */
void cycler(int *array, size_t size, int x, int y)
{
	int p;

	if ((y - x) > 0)
	{
		p = partition(array, x, y, size);
		cycler(array, size, x, (p - 1));
		cycler(array, size, (p + 1), y);
	}
}
