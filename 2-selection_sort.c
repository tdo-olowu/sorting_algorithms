#include "sort.h"


/**
 * selection_sort - selection sort done on an array
 * sel sort is probably the easiest O(n^2) sort to analyse
 * dh means "disarray's head"
 *
 * @array: the array to put in order (low to high)
 * @size: the number of elements in the array.
 * Return: none.
 */
void selection_sort(int *array, size_t size)
{
	size_t dh, mi;
	int *min_ptr;

	if (!array)
		return;

	for (dh = 0 ; dh < size ; ++dh)
	{
		/* find the minmum and swap with A(dh) */
		min_ptr = &array[dh];
		for (mi = dh + 1 ; mi < size ; ++mi)
		{
			if (array[mi] < *min_ptr)
				min_ptr = &array[mi];
		}
		swap(min_ptr, &array[dh]);
		print_array(array, size);
	}
}


/**
 * swap - exchanges the values of two positions in array
 * @a: the address of the first position
 * @b: the address of the second position
 * Return: nothing.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
