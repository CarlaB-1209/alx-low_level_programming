#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - reads a text file and printsit to POSIX standard output
 * @filename: name f the input file being read
 * @letters: number of letters to read and print
 * Return: number of letters read and printed
 *		0 (file could not be opened or read)
 *		0 (filename is NULL)
 *		0 (write fails or does not return expectd no bytes)
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff = malloc((sizeof(char) * letters) + 1);

	FILE *file = fopen(filename, "r");

	ssize_t bytes_read = fread(buff, sizeof(char), letters, file);
	ssize_t bytes_written = fwrite(buff, sizeof(char), bytes_read, stdout);

	if (filename == NULL)
		return (0);

	if (file == NULL)
		return (0);

	if (buff == NULL)
	{
		fclose(file);
		return (0);
	}

	if (bytes_read <= 0)
	{
		free(buff);
		fclose(file);
		return (0);
	}

	free(buff);

	fclose(file);

	if (bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}

