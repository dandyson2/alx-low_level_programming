#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - function that reads a text file
 * and prints it to the POSIX standard output
 * @filename: File name to read
 * @letters: Number of letters to read
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int one;
	ssize_t text_l, text_w;
	char *c_read;

	if (filename == NULL)
		return (0);

	one = open(filename, O_RDONLY);
	if (one == -1)
		return (0);

	c_read = malloc(sizeof(char) * letters);
	if (c_read == NULL)
	{
		close(one);
		return (0);
	}

	text_l = read(one, c_read, letters);
	close(one);

	if (text_l == -1)
	{
		free(c_read);
		return (0);
	}

	text_w = write(STDOUT_FILENO, c_read, text_l);
	free(c_read);

	if (text_l != text_w)
		return (0);

	return (text_w);
}
