#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0s and 1s containing the binary number
 * Return: converted number (success) or 0 (one char is not0 or 1, b is NULL)
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int converted = 0;

	int counter;

	if (b == NULL)
	{
		return (0);
	}

	for (counter = 0; b[counter] != '\0'; counter++)
	{
		if (b[counter] != '0' && b[counter] != '1')
			return (0);

		converted = (converted << 1) | (b[counter] - '0');
	}

	return (converted);
}
