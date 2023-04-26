#include "main.h"

/**
 * print_alphabet_x10 - prints the lowercase alphabet ten times
 */

void print_alphabet_x10(void)
{
	int arr[26] = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

	int i;

	for (i = 1; i <=10; i++)
		_putchar(arr);
	_putchar('\n');

}
