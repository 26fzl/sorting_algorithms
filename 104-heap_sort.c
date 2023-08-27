#include "sort.h"

/**
* stupify - recurrssive heapfiy function
* @array: Array to sort
* @heap: size of heap data
* @i: index
* @size: size of array
*/

void stupify(int *array, int heap, int i, int size)
{
	int lar = i, lf = 2 * i + 1, ri = 2 * i + 2, t;

	if (lf < heap && array[lf] > array[lar])
		lar = lf;
	if (ri < heap && array[ri] > array[lar])
		lar = ri;
	if (lar != i)
	{
		t = array[i], array[i] = array[lar], array[lar] = t;
		print_array(array, size);
		stupify(array, heap, lar, size);
	}
}

/**
* heap_sort - Sorts array with heap sort algo
* @array: array to sort
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int x = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; x >= 0; x--)
		stupify(array, size, x, size);
	for (x = size - 1; x >= 0; x--)
	{
		temp = array[0];
		array[0] = array[x];
		array[x] = temp;
		if (x > 0)
			print_array(array, size);
		stupify(array, x, 0, size);
	}

}
