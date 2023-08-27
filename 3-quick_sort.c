#include "sort.h"

/**
 * swap - swap two int
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partition an array and using pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int a = low - 1, b;

	for (b = low; b <= high; b++)
	{
		if (array[b] <= pivot)
		{
			a++;
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_array(array, size);
			}
		}
	}
	return (a);
}
/**
 * lomuto_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int x;

	if (low < high)
	{
		x = partition(array, low, high, size);
		lomuto_qsort(array, low, x - 1, size);
		lomuto_qsort(array, x + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
