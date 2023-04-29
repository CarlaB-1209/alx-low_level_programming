#include "main.h"

/**
 * _isupper - cehcks for uppercase letters
 * @c: char to check
 *
 * Return: 0 got lowercase, 1 for uppercase letters
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	
	else
		return (0);
}
