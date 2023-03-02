#include "main.h"
#include <stdio.h>
/**
 * rot13 - a function that encodes a string using rot13
 * @r: ptr to string para
 * Return: *r
 */
char *rot13(char *r)
{
	int y;
	int z;
	char data1[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		char datarot[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

		for (y = 0; r[y] != '\0'; y++)
		{
			for (z = 0; z < 52; z++)
			{
				if (r[y] == data1[z])
				{
					r[y] = datarot[z];
					break;
				}
			}
		}

		return (r);
{
