#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


char *make_buffer(char *file);
void close_file_descriptors(int fd);

/**
 * make_buffer - Creates a buffer of 1024 bytes
 * @file: file using the buffer
 *
 * Return: pointer to the created buffer.
 */
char *make_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file_descriptors - as the name implies
 * @fd: the descriptors that will be closed
 */

void close_file_descriptors(int fd)
{
	int closer;

	closer = close(fd);

	if (closer == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies file contents from source to destination
 * @argc: argument count
 * @argv: list of arguments
 *
 * Return: 0 (success)
 *
 */

int main(int argc, char *argv[])
{
	int source, destination, writer, reader;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_source file_destination\n");
		exit(97);
	}

	buff = make_buffer(argv[2]);
	source = open(argv[1], O_RDONLY);
	reader = read(source, buff, 1024);
	destination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source == -1 || reader == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		writer = write(destination, buff, reader);
		if (destination == -1 || writer == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		reader = read(source, buff, 1024);
		destination = open(argv[2], O_WRONLY | O_APPEND);

	} while (reader > 0);

	free(buff);
	close_file_descriptors(source);
	close_file_descriptors(destination);

	return (0);
}
