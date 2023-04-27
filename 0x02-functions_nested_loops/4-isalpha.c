#include "main.h"

/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character being checked
 * Return: 1 if c is alphabetic, otherwise 0
 */

int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);

	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
