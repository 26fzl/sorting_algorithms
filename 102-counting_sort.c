#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int mx, x;

	for (mx = array[0], x = 1; x < size; x++)
	{
		if (array[x] > mx)
			mx = array[x];
	}

	return (mx);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *std, mx, x;

	if (array == NULL || size < 2)
		return;

	std = malloc(sizeof(int) * size);
	if (std == NULL)
		return;
	mx = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(std);
		return;
	}

	for (x = 0; x < (mx + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (max + 1); x++)
		count[x] += count[x - 1];
	print_array(count, mx + 1);

	for (x = 0; x < (int)size; x++)
	{
		std[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = std[x];

	free(std);
	free(count);
}
