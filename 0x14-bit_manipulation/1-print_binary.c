#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints a number in binary
 * @n: number to be printed in binary
 * Return: NULL
 */

void print_binary(unsigned long int n)
{
	int bitsize = sizeof(unsigned long int) * 8;

	unsigned long int right_bit = 1 << (bitsize - 1);

	int init_zero = 1;

	while (right_bit > 0)
	{
		if ((n & right_bit) != 0)
		{
			init_zero = 0;
			_putchar('1');
		}

		else if (!init_zero)
		{
			_putchar('1');
		}

		right_bit >>= 1;
	}

	if (init_zero)
	{
		_putchar('0');
	}
}
