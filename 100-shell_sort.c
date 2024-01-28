#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t spc, m, n;

	if (array == NULL || size < 2)
		return;

	for (spc = 1; spc < (size / 3);)
		spc = spc * 3 + 1;

	for (; spc >= 1; spc /= 3)
	{
		for (m = spc; m < size; m++)
		{
			n = m;
			while (n >= spc && array[n - spc] > array[n])
			{
				swap_ints(array + n, array + (n - spc));
				n -= spc;
			}
		}
		print_array(array, size);
	}
}
