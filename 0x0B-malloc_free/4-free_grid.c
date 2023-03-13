#include "main.h"
#include <stdlib.h>
/**
 * free_grid - function that frees a 2 dimensional grid
 * previously created by your alloc_grid function
 * @grid: ptr to ptr
 * @height: height of grid
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int y;

	for (y = 0; y < height; y++)
	{
		free(grid[y]);
	}
	free(grid);
}
