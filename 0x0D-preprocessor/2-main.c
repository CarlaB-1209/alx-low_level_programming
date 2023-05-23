#include <stdio.h>
#include "main.h"

/**
 * main - prints the name of the file the program was compiled from
 *
 * Return: Always 0
 */

#ifndef FILE

#define file __FILE__

#endif

int main(void)
{
	_putchar(file);
	_putchar('\n');

	return(0);
}
