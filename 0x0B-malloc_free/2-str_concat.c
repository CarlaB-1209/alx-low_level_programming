#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - links two strings and assigns appropriate memory space
 * @s1: input string 1
 * @s2: input string 2
 * Return: pointer to concatenated strings, terminate on NULL, NULL on failure
 *
 */

char *str_concat(char *s1, char *s2)
{
	char *conct;
	int i;
	int ci;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = ci = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[ci] != '\0')
		ci++;
	conct = malloc(sizeof(char) * (i + ci + 1));

	if (conct == NULL)
		return (NULL);
	i = ci = 0;
	while (s1[i] != '\0')
	{
		conct[i] = s1[i];
		i++;
	}

	while (s2[ci] != '\0')
	{
		conct[i] = s2[ci];
		i++;
		ci++;
	}
	conct[i] = '\0';
	return (conct);
}

