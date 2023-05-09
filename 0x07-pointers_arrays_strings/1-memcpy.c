#include "main.h"

/**
 * _memcpy - copies memory area
 * @src: source of copied memory
 * @dest: destination of copied memory
 * @n: number of bytes copied
 *
 * Return: pointer to the destination
 */

char *_memcpy(char *src, char *dest, unsigned int n)

{
	int r = 0;


	for (r = 0; r < n; r++)
	{
		dest[r] = src[r];
		n--;
	}

	return (dest);
}
