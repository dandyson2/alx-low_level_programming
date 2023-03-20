#include <stdlib.h>
#include "dog.h"
/**
 * init_dog - init a variable of type struct dog
 * @d: ptr to struct
 * @name: object
 * @age: object
 * @owner: object
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == 0)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
