#include "sort.h"

/**
 * quick_sort - Sorting an array of number using quick sort (Lomuto)
 * @array: Array
 * @size: Size of the array
 * Return: Nothing
**/

void quick_sort(int *array, size_t size)
{
	int lo, hi;

	lo = 0;
	hi = ((int) size) - 1;

	if (array == NULL || size < 2)
		return;

	quick_sort_lomuto(array, lo, hi, size);
}

/**
 * quick_sort_lomuto - Sorting an array of numbers using quick sort (Lomuto)
 * @array: Array
 * @lo: Array start index
 * @hi: Array end index
 * @size: SIze of the complete array
 * Return: Nothing
**/

void quick_sort_lomuto(int *array, int lo, int hi, size_t size)
{
	int piv;

	if (lo < hi)
	{
		piv = partition_lomuto(array, lo, hi, size);
		quick_sort_lomuto(array, lo, piv - 1, size);
		quick_sort_lomuto(array, piv + 1, hi, size);

	}
}


/**
 * partition_lomuto - Partition function for quick sort (Lomuto)
 * @array: Array
 * @lo: Array start index
 * @hi: Array end index
 * @size: Size of the complete array
 * Return: New pivot
**/

int partition_lomuto(int *array, int lo, int hi, size_t size)
{
	int piv_value, tmp, i, j;

	piv_value = array[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= piv_value)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
			i++;

		}
	}
	if (array[i] != array[hi])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		if (i != hi)
			print_array(array, size);
	}
	return (i);
}
