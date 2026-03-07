#include "main.h"

/**
 * _strncat - concatenates at most n bytes of src to dest
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to copy from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;  /* index pour dest */
	int j = 0;  /* index pour src */

	/* trouver la fin de dest */
	while (dest[i] != '\0')
		i++;

	/* copier au plus n caractères de src */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* ajouter le caractère de fin */
	dest[i] = '\0';

	return (dest);
}
