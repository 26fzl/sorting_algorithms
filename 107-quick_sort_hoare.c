#include "sort.h"

/**
 * swap - swap two int
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
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
	int piv = array[high];
	int x = low, y = high;

	while (1)
	{
		while (array[x] < piv)
			x++;
		while (array[y] > piv)
			y--;

		if (x < y)
		{
			swap(&array[x], &array[y]);
			print_array(array, size);
			x++;
			y--;
		}
		else
		{
			if (x != y)
				return (y);
			return (y - 1);
		}
	}
}
/**
 * hoare_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
	int x;

	if (low < high)
	{
		x = partition(array, low, high, size);
		if (x > low)
			hoare_qsort(array, low, x, size);
		hoare_qsort(array, x + 1, high, size);
	}
}
/**
 * quick_sort_hoare - Quick Sort Algorithme using hoare partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsort(array, 0, size - 1, size);
}
