#include "main.h"
#include <stdio.h>

/**
 * flip_bits - determines the number of bits that would need to be flipped
 * to get from one number to another
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_result = n ^ m;
	unsigned int counting = 0;

	while (bit_result != 0)
	{
		bit_result = bit_result & (bit_result - 1);
		counting++;
	}

	return (counting);
}
