#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets value ofa  bit at a specified index to 1
 * @n: input number
 * @index: specified index
 * Return: 1 (success) or -1 (error)
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int bit_number = 32;
	unsigned int sig_bit;

	if (index >= bit_number)
		return (-1);

	sig_bit = 1 << index;

	*n |= sig_bit;

	return (1);
}
