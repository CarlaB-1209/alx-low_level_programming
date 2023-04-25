#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase and uppercase.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char alphl[26] = "abcdefghijklmnopqrstuvwxyz";

	char alphU[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int i1;

	int i2;

	for (i1 = 0; i1 < 26; i1++)
	{
		putchar(alphl[i1]);
	}

	for (i2 = 0; i2 < 26; i2++)
	{
		putchar(alphU[i2]);
	}

	putchar('\n');

	return (0);
}

