#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - frees previously created 2D grid
 * @grid: 2d grid
 * @height: height dimension of grid
 * Description: frees memory of grid
 * Return: none
 *
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

