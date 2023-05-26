#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints name using a pointer to a function
 * @name: string to be printed by function
 * @f: pointer to function
 * Return: nothing
 **/

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

