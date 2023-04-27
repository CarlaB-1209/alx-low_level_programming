#include "main.h"

/**
 * print_sign - prints the sign of an integer
 * @n: the integer to be checked
 * Return: 1 if n is greater than zero
 * 0 if n is zero
 * -1 if n is greater than zero
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}

	else if (n < 0)
	{
		_putchar('-');
	}

	return (-1);
}
