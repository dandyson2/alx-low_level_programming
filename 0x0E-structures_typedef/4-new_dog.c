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
	int i, lenN, lenO;

	struct dog *my_dog = NULL;

	lenN = 0;
	while (name[lenN] != '\0')
		lenN++;
	lenO = 0;
	while (owner[lenO] != '\0')
		lenO++;

	my_dog = malloc(sizeof(struct dog));
	if (my_dog == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	my_dog->name = malloc(lenN + 1);
	if (my_dog->name == NULL)
	{
		free(my_dog->name);
		free(my_dog);
		return (NULL);
	}
	my_dog->owner = malloc(lenO + 1);
	if (my_dog->owner == NULL)
	{
		free(my_dog->name);
		free(my_dog->owner);
		free(my_dog);
		return (NULL);
	}

	for (i = 0; i <= lenN; i++)
		my_dog->name[i] = name[i];
	for (i = 0; i <= lenO; i++)
		my_dog->owner[i] = owner[i];
	my_dog->age = age;
	return (my_dog);
}
