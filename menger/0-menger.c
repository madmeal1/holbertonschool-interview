#include <stdio.h>

#include "menger.h"

/**
 * is_hole - Checks whether a given coordinate falls into an empty
 *           (hole) cell of a Menger sponge, at any zoom level
 *
 * @x: X coordinate of the cell
 * @y: Y coordinate of the cell
 * @size: Size (width/height) of the sponge
 *
 * Return: 1 if the cell is a hole, 0 otherwise
 */
static int is_hole(int x, int y, int size)
{
	while (size > 1)
	{
		size /= 3;
		if ((x / size) % 3 == 1 && (y / size) % 3 == 1)
			return (1);
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level
 *
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = 1;
	while (level-- > 0)
		size *= 3;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
			putchar(is_hole(x, y, size) ? ' ' : '#');
		putchar('\n');
	}
}
