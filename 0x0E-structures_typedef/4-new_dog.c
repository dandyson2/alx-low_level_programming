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

	struct dog *_new_dog = NULL;

	aniN = 0;
	while (name[aniN] != '\0')
		aniN++;
	aniO = 0;
	while (name[aniO] != '\0')
		aniO++;

	_new_dog = malloc(sizeof(struct dog));
	if (_new_dog->owner == NULL)
	{
		free(_new_dog->name);
		free(_new_dog->owner);
		free(_new_dog);
		return (NULL);
	}
	for (p = 0; p <= aniN; p++)
		_new_dog->name[p] = name[p];
	for (p = 0; p <= aniO; p++)
		_new_dog->owner[p] = owner[p];
	_new_dog->age = age;
	return (_new_dog);
}
