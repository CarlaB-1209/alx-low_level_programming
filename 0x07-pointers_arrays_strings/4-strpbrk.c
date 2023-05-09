#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: input string being analyzed
 * @accept: template input
 *
 * Return:  a pointer to the byte in s that matches accept
 * or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept);
{
	int k;

	while (*s)
	{
		for (k = 0; accept[k]; k++)
		{
			if (*s == accept[k])
				return (s);
		}
		s++;
	}

	return ('\0');
}

