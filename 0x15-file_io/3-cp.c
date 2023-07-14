#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * exitError - prints exit code
 */

void exitError(int ExitCode, const char *Error_M)
{
	dprintf(STDERR_FILENO, "%s\n", Error_M);
	exit(ExitCode);
}

/**
 * copy_file - copies contents of one file to another
 * @file_from: source file
 * @file_to: destination file
 * Return: NULL
 */

void copy_file(const char *file_from, const char *file_to)
{
	int fileFrom = open(file_from, O_RDONLY);
	int fileTo = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	char buff[BUFFER_SIZE];
	ssize_t read_bytes, written_bytes;

	if (fileFrom == -1)
		exitError(98, "Error: Can't read from file NAME_OF_THE_FILE");
	if (fileTo == -1)
	{
		close(fileFrom);
		exitError(99, "Error: Can't write to NAME_OF_THE_FILE");
	}

	while ((read_bytes = read(fileFrom, buff, BUFFER_SIZE)) > 0)
	{
		written_bytes = write(fileTo, buff, read_bytes);
		if (written_bytes == -1)
		{
			close(fileFrom);
			close(fileTo);
			exitError(99,
				"Error: Can't write to NAME_OF_THE_FILE");
		}
	}
	if (read_bytes == -1)
	{
		close(fileFrom);
		close(fileTo);
		exitError(98, "Error: Can't read from file NAME_OF_THE_FILE");
	}

	if (close(fileFrom) == -1)
		exitError(100, "Error: Can't close fd FD_VALUE");

	if (close(fileTo) == -1)
		exitError(100, "Error: Can't close fd FD_VALUE");
}
