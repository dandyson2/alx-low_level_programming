#include "main.h"
#include <string.h>
/**
 * puts2 - a function that prints every other character of a string
 * starting with the first character, followed by a new line
 * @str: str param
 */
void puts2(char *str)
{
int len, 1;

len = strlen(str);
for (i = 0; i < len; i += 2)
_putchar(str[i]);
_putchar('\n');
}
