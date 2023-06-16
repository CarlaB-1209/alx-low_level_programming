#include "main.h"
#include <stdlib.h>

/**
 * read_textfile reads a text file and prints it to POSIX standard output
 * @filename: name of file being read
 * @letters: number of letters to be read and printed
 * Return: number of letters that were read and printed otherwise NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	t = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);

	free(buffer);

	close(fd);

	return (w);
}
