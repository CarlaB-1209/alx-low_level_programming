#include <stdio.h>
#include "main.h"

void first(void) __attribute__ ((constructor));

/**
 * first - prints text before the main function is executed
 */

void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
