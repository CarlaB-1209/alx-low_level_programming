#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - adds a series of positive numbers
 * @argc: Count arguments
 * @argv: Arguments
 *
 * Return: 0 (Success), 1 (Error - special characters present)
 */

int main(int argc, char *argv[])

{

	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))

		{
			str_to_int = atoi(argv[count]); 
			sum = sum + str_to_int;
		}

		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", sum);

	return (0);
}

