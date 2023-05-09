#include "main.h"

/**
 * *_strchr - locates a character in a string
 * @s: input string being investigated
 * @c: input character being searched for
 *
 * Return: a pointer to the first occurrence of the character c
 * or NULL if character not found
 */

char *_strchr(char *s, char c)

{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}

	return (0);
}

