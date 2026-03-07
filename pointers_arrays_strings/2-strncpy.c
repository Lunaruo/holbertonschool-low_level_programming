#include "main.h"

/**
 * _strncpy - copies a string, using at most n bytes from src
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	/* Copier les caractères de src dans dest */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* Remplir le reste de dest avec '\0' si n > longueur de src */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
