#include <stdio.h>
#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 *new_dog - creates a new dog
 *@name: name of the dog
 *@age: age of the dog
 *@owner: owner of the dog
 *
 *Return: pointer to new dog, or NULL if it fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_copy;
	char *owner_copy;

	if (name == NULL || owner == NULL)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	name_copy = malloc(sizeof(char) * (_strlen(name) + 1));
	if (name_copy == NULL)
	{
		free(dog);
		return (NULL);
	}

	owner_copy = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(dog);
		return (NULL);
	}

	_strcpy(name_copy, name);
	_strcpy(owner_copy, owner);

	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}

