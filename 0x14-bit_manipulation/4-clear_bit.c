#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the vlaue of a bit at a specified index to 0
 * @n: input number
 * @index: specified index
 * Return: 1 (success) or -1 (error)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int number_of_bits = 32;
	unsigned long int right_end_bit;

	if (index >= number_of_bits)
		return (-1);

	right_end_bit = 1 << index;

	*n &= ~right_end_bit;

	return (1);
}

