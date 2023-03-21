#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - function that creates a new dog
 * @name: object 1
 * @age: object 2
 * @owner: object 3
 * Return: NULL if fail
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int p, aniN, aniO;

	struct dog *n_dog = NULL;

	aniN = 0;
	while (name[aniN] != '\0')
		aniN++;
	aniO = 0;
	while (owner[aniO] != '\0')
		aniO++;

	n_dog = malloc(sizeof(struct dog));
	if (n_dog == NULL)
	{
		free(n_dog);
		return (NULL);
	}
	n_dog->name = malloc(aniN + 1);
	if (n_dog->name == NULL)
	{
		free(n_dog->name);
		free(n_dog);
		return (NULL);
	}
	n_dog->owner = malloc(aniO + 1);
	if (n_dog->owner == NULL)
	{
		free(n_dog->name);
		free(n_dog->owner);
		free(n_dog);
		return (NULL);
	}

	for (p = 0; p <= aniN; p++)
		n_dog->name[p] = name[p];
	for (p = 0; p <= aniO; p++)
		n_dog->owner[p] = owner[p];
	n_dog->age = age;
	return (n_dog);
}
