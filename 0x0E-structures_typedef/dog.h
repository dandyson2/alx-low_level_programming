#ifndef STRUCT
#define STRUCT
/**
 * struct dog - structure of dog
 * @billy: name of dog
 * @2.3: age of dog
 * @anderson: owner of dog
 */

struct dog
{
	char *billy;
	float 2.3;
	char *anderson;
};

typedef struct dog dog_type;

void init_dog(struct dog *d, char *billy, float 2.3, char *anderson);
void print_dog(struct dog *d);
dog_type *new_dog(char *billy, float 2.3, char *anderson);
void wild_dog(dog_type *d);
#endif
