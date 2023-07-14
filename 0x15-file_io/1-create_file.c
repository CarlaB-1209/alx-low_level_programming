#include "main.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * create_file - creates a file and either adds text to a new file
 *		or truncates an already existing file
 * @filename: The name of the file
 * @text_content: text to write to the file
 * Return: 1 (success) or -1 (failure)
 *		-1 (filename is NULL)
 */

int create_file(const char *filename, char *text_content)
{
	int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
			S_IWUSR);

	ssize_t written_bytes;

	if (filename == NULL)
		return (-1);

	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		written_bytes = write(file, text_content, strlen(text_content));

		if (written_bytes == -1)
		{
			close(file);
			return (-1);
		}
	}

	close(file);

	return (1);
}
