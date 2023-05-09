#include "main.h"

/**
 * _memcpy - copies memory area
 * @src: source of copied memory
 * @dest: destination of copied memory
 * @n: number of bytes copied
 *
 * Return: pointer to the destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	int r = 0;

	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}

	return (dest);
}

