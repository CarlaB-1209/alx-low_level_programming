#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

/**
 * append_text_to_file - adds text at the end of a file
 * @filename: name of the file ebing edited
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 (success) or -1 (failure)
 *		-1 (filename is NULL)
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int my_file = open(filename, O_WRONLY | O_APPEND);

	ssize_t bytes_to_write;

	if (filename == NULL)
		return (-1);

	if (my_file == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytes_to_write = write(my_file, text_content,
				strlen(text_content));

		if (bytes_to_write == -1)
		{
			close(my_file);
			return (-1);
		}
	}

	close(my_file);

	return (1);
}
