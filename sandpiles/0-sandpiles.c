
#include "sandpiles.h"

/* Checks if a sandpile grid is stable */
int sandpile_is_stable(int arr[3][3])
{
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (arr[y][x] > 3)
				return (0);
	return (1);
}

/* Adds two sandpiles together */
void sandpile_add(int dest[3][3], int src[3][3])
{
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			dest[y][x] += src[y][x];
}

/* Prints a sandpile grid */
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

/* Performs a single toppling round on a sandpile */
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

/* Sums two sandpiles and stabilizes the result */
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
