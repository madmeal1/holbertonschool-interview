#ifndef SANDPILES_H
#define SANDPILES_H
#include <stdio.h>
#include <stdlib.h>

/**
 * sandpiles_sum - Ajoute des sandpiles et vérifie si c'est bon
 * @firstGrid: Premier sandpile
 * @secondGrid: Deuxième sandpile
 */
void sandpiles_sum(int firstGrid[3][3], int secondGrid[3][3]);

/**
 * print_grids - Affiche la grille
 * @grid: Sandpile
 */
void print_grids(int grid[3][3]);

/**
 * is_unstable - Vérifie si la grille est instable
 * @grid: Sandpile
 * Return: 1 si instable, 0 sinon
 */
int is_unstable(int grid[3][3]);

/**
 * stabilize_grid - Stabilise la grille
 * @grid: Sandpile
 */
void stabilize_grid(int grid[3][3]);

/**
 * add_grids - Ajoute les éléments de deux grilles
 * @firstGrid: Premier sandpile
 * @secondGrid: Deuxième sandpile
 */
void add_grids(int firstGrid[3][3], int secondGrid[3][3]);

#endif /* SANDPILES_H */
