#include <stdlib.h>
#include "lists.h"

/**
 * list_len - determines the number of elements in a linked list
 * @h: pointer to the next element in the list_t list
 *
 * Return: number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}

	return (n);
}

