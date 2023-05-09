#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: address of memory
 * @b: size of constant byte
 * @n: number of bytes that will be changed
 *
 * Return: a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)

{
	int i = 0;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}

	return (s);
}
