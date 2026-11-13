#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 *
 * Description: prints the name, age and owner of a dog
 */
void print_dog(struct dog *d)
{
    if (d == NULL)
        return;

    printf("Name: %s\n", d->name == NULL ? "(nil)" : d->name);
    printf("Age: %f\n", d->age);
    printf("Owner: %s\n", d->owner == NULL ? "(nil)" : d->owner);
}
