#include "main.h"

/**
 * _isdigit - checks for digits 0 - 9
 * @c: the char that will be checked
 * Return: 0 or 1
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
