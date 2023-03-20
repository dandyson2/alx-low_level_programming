#ifndef STRUCT
#define STRUCT
/**
 * struct dog - structure of dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_type;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_type *new_dog(char *name, float age, char *owner);
void wild_dog(dog_type *d);
#endif
