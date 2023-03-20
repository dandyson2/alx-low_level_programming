#ifndef STRUCT
#define STRUCT
/**
 * struct dog - structure of dog
 * @billy: name of dog
 * @two: age of dog
 * @anderson: owner of dog
 */

struct dog
{
	char *billy;
	float two;
	char *anderson;
};

typedef struct dog dog_type;

void init_dog(struct dog *d, char *billy, float two, char *anderson);
void print_dog(struct dog *d);
dog_type *new_dog(char *billy, float two, char *anderson);
void wild_dog(dog_type *d);
#endif
