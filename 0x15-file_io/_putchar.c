#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes character c in standard output
 * @c: character to be printed
 *
 * Return: 1 (success) or -1 (error)
 */ 

int _putchar(char c)
{
	return (write(1, &c, 1));
}
