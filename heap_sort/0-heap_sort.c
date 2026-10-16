#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Sifts a node down to restore the max-heap property
 *
 * @array: The array representing the heap
 * @size: Total number of elements in @array (used for printing)
 * @root: Index of the node to sift down
 * @end: Number of elements in the heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, largest;

	while ((child = 2 * root + 1) < end)
	{
		largest = root;
		if (array[child] > array[largest])
			largest = child;
		if (child + 1 < end && array[child + 1] > array[largest])
			largest = child + 1;
		if (largest == root)
			return;
		swap_ints(&array[root], &array[largest]);
		print_array(array, size);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the sift-down Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i, end;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);

	for (end = size - 1; end > 0; end--)
	{
		swap_ints(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, size, 0, end);
	}
}
