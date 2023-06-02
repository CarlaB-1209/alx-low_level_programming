#include <stdio.h>
#include <stdlib>

void first(void) __attribute__ ((constructor));

/**
 * first - prints text before the main function is executed
 */

void first(void)
{
	char 1[] = "You're beat! and yet, you must allow";
	char 2[] = "I bore my house upon my back";

	printf(%s'\n', 1);
	printf(%s'\n', 2);
}
