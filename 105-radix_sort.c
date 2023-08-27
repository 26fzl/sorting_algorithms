#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int mx;
	size_t x, lsd;

	if (!array || size < 2)
		return;

	mx = 0;
	for (x = 0; x < size; x++)
		if (array[x] > mx)
			mx = array[x];

	for (lsd = 1; mx / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *out_arr, l, m;
	size_t y, z;

	out_arr = malloc(sizeof(int) * size);

	for (y = 0; y < size; y++)
		count_arr[(array[y] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		count_arr[l] += count_arr[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
	}

	for (z = 0; z < size; z++)
		array[z] = out_arr[z];

	free(out_arr);
}
