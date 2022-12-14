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
 * bubble_sort - sorts intArr asc via bubblesort algo
 * @array: array of integers
 * @size: number of ints in array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int i, gg = 1, posCount;

	if (!array || size < 2)
	{
		return;
	}
	posCount = size - 1;
	while (gg)
	{
		gg = 0;
		for (i = 0; i < posCount; i++)
		{
			if (array[i] > array[i + 1])
			{
				swpints(&array[i], &array[i + 1]);
				print_array(array, size);
				gg = 1;
			}
		}
		posCount--;
	}
}
