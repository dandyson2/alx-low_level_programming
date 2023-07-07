#include "hash_tables.h"

/**
* hash_djb2 - Function that implements the djb2 algorithm.
* @str: The hash string
* Return: Hash calculated
*/

unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash = 5381;

for (; *str; str++)
{
hash = ((hash << 5) + hash) +*str; /* hash * 33 + count */
}

return (hash);
}
