
#include "sandpiles.h"

/**
 * sandpile_is_stable - Checks if a sandpile grid is stable
 * @arr: 3x3 sandpile grid
 *
 * Return: 1 if stable, 0 if unstable
 */
int sandpile_is_stable(int arr[3][3])
{
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (arr[y][x] > 3)
				return (0);
	return (1);
}

/**
 * sandpile_add - Adds two sandpiles together
 * @dest: Destination sandpile grid (result)
 * @src: Source sandpile grid (added to dest)
 */
void sandpile_add(int dest[3][3], int src[3][3])
{
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			dest[y][x] += src[y][x];
}

/**
 * sandpile_print - Prints a sandpile grid
 * @arr: 3x3 sandpile grid to print
 */
void sandpile_print(int arr[3][3])
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (x)
				printf(" ");
			printf("%d", arr[y][x]);
		}
		printf("\n");
	}
}

/**
 * sandpile_topple - Performs a single toppling round on a sandpile
 * @arr: 3x3 sandpile grid to topple
 */
void sandpile_topple(int arr[3][3])
{
	int buffer[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (arr[y][x] > 3)
			{
				arr[y][x] -= 4;
				if (y > 0)
					buffer[y - 1][x]++;
				if (x > 0)
					buffer[y][x - 1]++;
				if (y < 2)
					buffer[y + 1][x]++;
				if (x < 2)
					buffer[y][x + 1]++;
			}
		}
	}
	sandpile_add(arr, buffer);
}

/**
 * sandpiles_sum - Sums two sandpiles and stabilizes the result
 * @gridA: First sandpile grid (result)
 * @gridB: Second sandpile grid
 */
void sandpiles_sum(int gridA[3][3], int gridB[3][3])
{
	sandpile_add(gridA, gridB);
	while (!sandpile_is_stable(gridA))
	{
		printf("=\n");
		sandpile_print(gridA);
		sandpile_topple(gridA);
	}
}
