#include "sort.h"

/**
 *bubble_sort - sorts an array of integers in ascending orde
 *@array: the array to be sort
 *@size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t y, x;
	int n;

	if (size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				n = array[y];
				array[y] = array[y + 1];
				array[y + 1] = n;
				print_array(array, size);
			}
		}
	}
}
