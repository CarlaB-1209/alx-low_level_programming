#include "main.h"

/**
 * _islower - checks if a character is lowercase
 * @c: character to be checked
 * Return: 1 is character is lowercase, otherwise 0
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
