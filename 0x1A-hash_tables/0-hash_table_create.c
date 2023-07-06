#include "hash_tables.h"

/**
 * hash_table_create - Function that creates a hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table
 * If something went wrong, return NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table_created;
	unsigned long int i = 0;

	/* Allocate space for the hash table */
	hash_table_created = malloc(sizeof(hash_table_t));
	if (hash_table_created == NULL)
		return (NULL);

	hash_table_created->size = size;
	hash_table_created->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table_created->array == NULL)
	{
		free(hash_table_created); /* Cleanup on error */
		return (NULL);
	}

	while (i < size)
	{
		hash_table_created->array[i] = NULL;
		i++;
	}

	return (hash_table_created);
}
