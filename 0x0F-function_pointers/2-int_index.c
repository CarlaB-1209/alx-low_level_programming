#include "function_pointers.h"

/**
 * int_index - searches an array for an integer
 * and returns the index for first element
 * for which the function does not return 0
 * @array: array
 * @size: size of elements in the array
 * @cmp: pointer to the function being used to compare values
 * Return: 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}

