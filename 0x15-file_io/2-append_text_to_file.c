#include "main.h"

/**
 * append_text_to_file - function that appends text
 * at the end of a file
 * @filename: Filename
 * @text_content: Content added
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int _file_create;
	int _file_letters;
	int _check_;

	if (!filename)
		return (-1);

	_file_create = open(filename, O_WRONLY | O_APPEND);

	if (_file_create == -1)
		return (-1);

	if (text_content)
	{
		for (_file_letters = 0; text_content[_file_letters]; _file_letters++)
			;
		_check_ = write(_file_create, text_content, _file_letters);

		if (_check_ == -1)
			return (-1);
	}

	close(_file_create);

	return (1);
}
