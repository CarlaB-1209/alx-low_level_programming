#include <stdio.h>

/**
 * main - Prints single digit base 10 numbers ie. print 0-9.
 *
 * Return: Always 0 (Success)
 */

int main(void)

{
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d", i);
	}

	putchar('\n');

	return (0);
}

