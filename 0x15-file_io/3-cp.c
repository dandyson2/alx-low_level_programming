#include "main.h"
#include <stdio.h>

/**
 * _file_ch_err - checks if files can be opened
 * @file_from: File to copy from
 * @file_to: File to copy to
 * @argv: Argument check
 * Return: Void
 */
void _file_ch_err(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Check codes
 * @argc: Argument numbers
 * @argv: Argument checks
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, msg_err;
	ssize_t file_chars, ch;
	char _run[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	_file_ch_err(file_from, file_to, argv);

	file_chars = 1024;
	while (file_chars == 1024)
	{
		file_chars = read(file_from, _run, 1024);
		if (file_chars == -1)
			_file_ch_err(-1, 0, argv);
		ch = write(file_to, _run, file_chars);
		if (ch == -1)
			_file_ch_err(0, -1, argv);
	}

	msg_err = close(file_from);
	if (msg_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	msg_err = close(file_to);
	if (msg_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	return (0);
}
