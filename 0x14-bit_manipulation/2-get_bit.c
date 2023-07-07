#include "main.h"
#include <stdio.h>

/**
 * get_bit - returns the vlaue ofa bit at a secified index
 * @n: input number
 * @index: specified index
 * Return: value of bit (success) or -1 (error)
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit_number = 32;
	unsigned int important_bit;
	int bit_value;

	if (index >= bit_number)
		return (-1);

	important_bit = 1 << index;

	bit_value = (n & important_bit) != 0;

	return (bit_value);
}
