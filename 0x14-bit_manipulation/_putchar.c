#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to standard output
 * @c: The character to print.
 *
 * Return: 1 (duccess) or -1 (error_
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
