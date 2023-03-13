#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - function that returns a pointer
 *  to a 2 dimensional array of integers
 *  @width: width of matrix
 *  @height: height of matrix
 *  Return: ptr of ptr to null
 */
int **alloc_grid(int width, int height)
{
	int y, z, m, n;
	int **w;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	else
	{
		w = (int **) malloc(height * sizeof(int *));
		if (!w)
		{
			free(w);
			return (NULL);
		}
		for (y = 0; y < height; y++)
		{
			w[y] = (int *) malloc(width * sizeof(int));
			if (!w[y])
			{
				for (z = 0; z <= y; z++)
					free(w[z]);
				free(w);
				return (NULL);
			}
		}
		for (m = 0; m < height; m++)
		{
			for (n = 0; n < width; n++)
			{
				w[m][n] = 0;
			}
		}
		return (w);
	}
}
