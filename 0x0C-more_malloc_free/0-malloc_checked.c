#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory using malloc and checks that tit worked
 * @b: number of bytes that will be allocated
 * Return: a pointer to the allocated memory (success)
 */

void *malloc_checked(unsigned int b)
{
	void *point;

	point = malloc(b);

	if (point == NULL)
		exit(98);

	return (point);
}
