#include <stdio.h>

/**
 * main - lists all natural numbers below 1024 which are multiples of 4 or 5
 * Return: always 0 
 */

int main(void)
{
	int i; 
	int sum = 0; 

	for (i = 0; i < 1024; i++)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			sum = sum + i;
	}

	printf("%d\n", sum);

	return (0);
}

