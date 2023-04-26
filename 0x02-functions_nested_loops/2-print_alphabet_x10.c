#include "main.h"

/**
 * print_alphabet_x10 - prints the lowercase alphabet
 */

void print_alphabet_x10(void)
{
	char char;

	int i;

	i = 0;

	while (i <10)
	{
		ch = 'a';

		while (ch <='z')
		{
			_putchar(ch);
			ch++;
		}

		_putchar('\n');

		i++;
	}
}
