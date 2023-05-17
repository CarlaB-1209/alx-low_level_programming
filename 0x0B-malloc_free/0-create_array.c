#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_array - creates an array of specified size and assigns char c
 * @size: specified size of the array
 * @c: char that will be assigned
 * Return: pointer to array or NULL if size is zero
 *
 */

char *create_array(unsigned int size, char c)
{
	char *str;

	unsigned int i;

	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;

	return (str);
}
