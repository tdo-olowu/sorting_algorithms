#include "sort.h"



/**
 * bubble_sort - sorts an array acc/ to bubble sort
 * aka sinking sort. in the code, ssb is the length of
 * the sorted sub-array to the right end.
 * ssb increments with each pass of the bubble_sort
 *
 * @array: a pointer to an array of integers
 * @size: the number of items in the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t lvl, j, ssb;

	if (!array)
		return;
	if (size <= 1)
		return;

	for (lvl = 0, ssb = 0; lvl < size - 1 ; ++lvl, ++ssb)
	{
		for (j = 0 ; j < size - 1 - ssb ; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}


/** SIMPLE SUBROUTINES */
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
