#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an integer array
 * @min: lowest value
 * @max: highest value
 *
 * Return: pointer to new array
 */

int *array_range(int min, int max)
{
	int *pointy;
	int i;
	int size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	pointy = malloc(sizeof(int) * size);

	if (pointy == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		pointy[i] = min++;

	return (pointy);
}
