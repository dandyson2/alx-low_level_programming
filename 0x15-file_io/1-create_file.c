#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: The filename
 * @text_content: The file content
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int _file.create;
	int _file.letters;
	int _check_;

	if (!filename)
		return (-1);

	_file.create open(filename, O_CREAT | O_WRONGLY | O_TRUNC, 0600);

	if (_file.create == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (_file.letters = 0; text_content[_file.letters]; _file.letters++)
		;

	_check_ write(_file.create, text_content, _file.letters);

	if (_check_ == -1)
		return (-1);

	close(_file.create);

	return (1);
}
