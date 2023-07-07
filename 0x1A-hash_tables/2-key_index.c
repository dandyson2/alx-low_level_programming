#include "hash_tables.h"

/**
 * key_index - Function that gives the index of a key
 * @key: Key to index
 * @size: Array size of hash table
 * Return: The index at which the key/value pair
 * should be stored in the array of hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = hash_djb2(key);
	unsigned long int index = hash % size;

	return (index);
}
