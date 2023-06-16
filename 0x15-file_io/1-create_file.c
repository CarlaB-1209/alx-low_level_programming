#include "main.h"

/**
 * create_file - creates a file
 * @filename: pointer to the name of the file that will be created
 * @text_content: pointer to a NULL terminated string to write to the file
 *
 * Return: 1 (success), -1 (failure or if filename is NULL)
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int w;
	int length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	w = write(fd, text_content, length);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
