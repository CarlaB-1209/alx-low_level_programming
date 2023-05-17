#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function that counts word number in the string
 * @s: string to be evaluated
 *
 * Return: number of words
 */

int count_word(char *s)
{
	int marker;
	int c;
	int w;

	marker = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			marker = 0;
		else if (marker == 0)
		{
			marker = 1;
			w++;
		}
	}

	return (w);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */

char **strtow(char *str)
{
	char **matrix;
	char *tmp;
	int i;
	int k = 0;
	int len = 0;
	int words;
	int c = 0;
	int start;
	int end;

	while (*(str + len))
		len++;

	words = count_word(str);

	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));

	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));

				if (tmp == NULL)
					return (NULL);

				while (start < end)
					*tmp++ = str[start++];

				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}

		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

