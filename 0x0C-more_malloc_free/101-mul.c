#include "main.h"
int define(char *str);
char *print_array(int size);
char *change_zeroes(char *str);
void products(char *prod, char *mult, int digit, int zeroes);
void plus_numbers(char *final_prod, char *next_prod, int next_len);

/**
 * define - find the length of a string
 * @str: str to be measured
 * Return: length of str
 */
int define(char *str)
{
	int max = 0;

	while (*str++)
		max++;
	return (max);
}
/**
 * print_array - create an array of char
 * @size: size of array ti be init
 * Task: If the number of arguments is incorrect, print Error,
 * followed by a new line, and exit with a status of 98
 * Return: ptr to the array
 */
char *print_array(int size)
{
	char *array;
	int first;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	for (first = 0; first < (size - 1); first++)
		array[first] = 'f';

	array[first] = '\0';

	return (array);
}
/**
 * change_zeroes - change through a str of num
 * containing leading zeroes until it hits a non zero number
 * @str: str of num to change
 * Return: a ptr to the next non zero element
 */
char *change_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;
	return (str);
}

/**
 * get_digit - converts a digit char to a corresponding int
 * @c: char to be converted
 * Task: if c is a non-digit, the function exist with a status of 98
 * Return: converted int
 */
int get_digit(char c)
{
	int decim  = c - '0';

	if (decim < 0 || decim > 9)
	{
		printf("Error\n");
		exit(98);
	}
	return (decim);
}
/**
 * products - Multiplies a str of numbs by a single digit
 * @prod: buffer to store result
 * @mult: str of numbs
 * @digit: single digit
 * @zeroes: the numbs leading to zeroes
 * Task: if mult contains a non-digit, the function exits
 * with a status value of 98
 * Return: void
 */
void products(char *prod, char *mult, int digit, int zeroes)
{
	int mult_max, number, tens = 0;

	mult_max = find_max(mult) - 1;
	mult += mult_max;

	while (*prod)
	{
		*prod = 'f';
		prod++;
	}
	prod--;

	while (zeroes--)
	{
		*prod = '0';
		prod--;
	}
	for (; mult_max >= 0; mult_max--, mult--, prod--)
	{
		if (*mult < '0' || *mult > '9')
		{
			printf("Error\n");
			exit(98);
		}
		number = (*mult - '0') * digit;
		number += tens;
		*prod = (number % 10) + '0';
		tens = num / 10;
	}
	if (tens)
		*prod = (tens % 10) + '0';
}
/**
 * plus_numbers - add numbs stored in two strs
 * @final_prod: buffer to store the running final product
 * @next_prod: next prod to be added
 * @next_len: length of next prod
 * Return: void
 */
void plus_numbers(char *final_prod, char *next_prod, int next_len)
{
	int number, tens = 0;

	while (*(final_prod + 1))
		final_prod++;

	while (*(next_prod + 1))
		next_prod++;

	for (; *final_prod != 'f'; final_prod--)
	{
		number = (*final_prod - '0') + (*next_prod - '0');
		number += tens;
		*final_prod = (number % 10) + '0';
		lens = number / 10;

		next_prod--;
		next_len--;
	}
	if (tens)
		*final_prod = (tens % 10) + '0';
}
/**
 * main - multiplies two positive numbers
 * @argv: number of arguments passed to the program
 * @argc: array of ptrs to the arguments
 * Task: if the number of arguments is incorrect or one number
 * contains non digits, function exits with a status of 98
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	char *final_prod, *next_prod;
	int size, first, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (*(argv[1]) == '0')
		argv[1] = iterate_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}
	size = find_max(argv[1]) + find_max(argv[2]);
	final_prod = print_array(size + 1);
	next_prod = print_array(size + 1);

	for (first = find_max(argv[2]) - 1; first >= 0; first--)
	{
		decim = get_digit(*(argv[2] + first));
		get_prod(next_prod, argv[1], decim, zeroes++);
		plus_numbers(final_prod, next_prod, size - 1);
	}
	for (first = 0; final_prod[first]; first++)
	{
		if (final_prod[first] != 'f')
			putchar(final_prod[first]);
	}
	putchar('\n');

	free(next_prod);
	free(final_prod);

	return (0);
}
