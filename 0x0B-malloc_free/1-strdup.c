#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates string to new memory location
 * @str: string to be duplicated
 * Return: pointer to duplicated string or NULL if str = NULL
 *
 */

char *_strdup(char *str)
{
	char *abc;

	int i;

	int r = 0;

	if (str == NULL)
		return (NULL);

	i = 0;

	while (str[i] != '\0')
		i++;

	abc = malloc(sizeof(char) * (i + 1));

	if (abc == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		abc[r] = str[r];

	return (abc);
}
