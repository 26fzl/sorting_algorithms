#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, x, y;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			y = x;
			while (y >= gap && array[y - gap] > temp)
			{
				array[y] = array[y - gap];
				y -= gap;
			}
			array[y] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
