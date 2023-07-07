#include "main.h"
#include <stdio.h>

/**
 * get_endianness - checks endianness
 * Return: 1 (little endian) or 0 (big endian)
 */

int get_endianness(void)
{
	unsigned int number = 1;
	char *pointer = (char *)&number;

	if (*pointer == 1)
		return (1);

	else
		return (0);
}
