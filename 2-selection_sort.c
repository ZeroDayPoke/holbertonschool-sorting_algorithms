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
 * selection_sort - sorts intArr asc via selection sort
 * @array: array of integers
 * @size: number of ints in array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int i = 0, gg = 1, posCount, cmp = 0;

	if (!array || size < 2)
	{
		return;
	}
	posCount = size - 1;
	while (i < posCount)
	{
		if (gg == posCount + 1)
		{
			if (i != cmp)
			{
				swpints(&array[i], &array[cmp]);
				print_array(array, size);
			}
			i++;
			cmp = i;
			gg = i + 1;
			continue;
		}
		if (array[cmp] > array[gg])
		{
			cmp = gg;
		}
		gg++;
	}
}
