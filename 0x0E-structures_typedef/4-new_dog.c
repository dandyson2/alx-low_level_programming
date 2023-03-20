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

	struct dog *my_dog = NULL;

	aniN = 0;
	while (name[aniN] != '\0')
		aniN++;
	aniO = 0;
	while (owner[aniO] != '\0')
		aniO++;

	my_dog = malloc(sizeof(struct dog));
	if (my_dog == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	my_dog->name = malloc(aniN + 1);
	if (my_dog->name == NULL)
	{
		free(my_dog->name);
		free(my_dog);
		return (NULL);
	}
	my_dog->owner = malloc(aniO + 1);
	if (my_dog->owner == NULL)
	{
		free(my_dog->name);
		free(my_dog->owner);
		free(my_dog);
		return (NULL);
	}

	for (p = 0; p <= aniN; p++)
		my_dog->name[p] = name[p];
	for (p = 0; p <= aniO; p++)
		my_dog->owner[p] = owner[p];
	my_dog->age = age;
	return (my_dog);
}
