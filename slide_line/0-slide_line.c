#include "slide_line.h"

/**
 * compact_left - Moves all non-zero values of an array to the left,
 *                preserving their order, and fills the rest with zeros
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */
static void compact_left(int *line, size_t size)
{
	size_t i, pos;

	pos = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			pos++;
		}
	}
	for (i = pos; i < size; i++)
		line[i] = 0;
}

/**
 * merge_left - Merges contiguous identical values (after compaction),
 *              moving from left to right. Each merged value is only
 *              used once per merge
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */
static void merge_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			for (j = i + 1; j + 1 < size; j++)
				line[j] = line[j + 1];
			line[size - 1] = 0;
		}
	}
}

/**
 * reverse_line - Reverses the order of the elements of an array in place
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */
static void reverse_line(int *line, size_t size)
{
	size_t i;
	int tmp;

	for (i = 0; i < size / 2; i++)
	{
		tmp = line[i];
		line[i] = line[size - 1 - i];
		line[size - 1 - i] = tmp;
	}
}

/**
 * slide_line - Slides and merges an array of integers to the left
 *              or to the right, 2048-style
 *
 * @line: Pointer to the array of integers to slide & merge
 * @size: Number of elements in @line
 * @direction: Direction to slide, either SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
		reverse_line(line, size);

	compact_left(line, size);
	merge_left(line, size);
	compact_left(line, size);

	if (direction == SLIDE_RIGHT)
		reverse_line(line, size);

	return (1);
}
