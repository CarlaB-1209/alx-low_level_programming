#include "main.h"

/**
 * binary_to_uint - converts binary to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number (success) or 0 if b is NULL,
 * 0 if there is a number that is not 1 or 0 in the string
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int decimal = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		decimal = 2 * decimal + (b[i] - '0');
	}

	return (decimal);
}
