#include "sort.h"
/* try using the stack to print. put the print at end of function */


/**
 * quick_sort - quick sort using Lomuto partitioning
 * @array: the array to be sorted.
 * @size: the number of items in the array
 * Return: no return value.
 */
void quick_sort(int *array, size_t size)
{
	size_t p, i, j;

	if (array == NULL)
		return;

	if (size <= 1)
		return;

	/* partition */
	p = size - 1;
	for (i = 1, j = 0 ; j < p ; ++j)
	{
		if (array[j] <= array[p])
		{
			++i;
			swap(&array[j], &array[i]);
		}
	}
	swap(&array[i], &array[p]);

	/* recurse */
	quick_sort(array, i);
	quick_sort(&array[i + 1], size - 1 - i);
	print_array(array, size);
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
