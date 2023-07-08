#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
* hash_table_set - Function that add an element to hash table
* @ht: The hash table
* @key: The key, cannot be an empty string
* @value: The value
* Return: 1 if succeeded, otherwise 0.
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

char *value_copy = strdup(value);
if (value_copy == NULL)
return (0);

unsigned long int index = key_index((const unsigned char *)key, ht->size);
unsigned long int i = index;

while (ht->array[i] && strcmp(ht->array[i]->key, key) != 0)
i++;

if (ht->array[i])
{
free(ht->array[i]->value);
ht->array[i]->value = value_copy;
return (1);
}

hash_node_t *new = malloc(sizeof(hash_node_t));
if (!new)
{
free(value_copy);
return (0);
}

new->key = strdup(key);
if (!new->key)
{
free(new);
return (0);
}

new->value = value_copy;
new->next = ht->array[index];
ht->array[index] = new;

return (1);
}
