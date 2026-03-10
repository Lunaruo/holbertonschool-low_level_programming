#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space,
 * containing a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if it fails
 */

char *_strdup(char *str)
{
    char *copy;
    int i, len = 0;

    if (str == NULL)
        return (NULL);

    /* calculate length of str */
    while (str[len] != '\0')
        len++;

    /* allocate memory (+1 for '\0') */
    copy = malloc(sizeof(char) * (len + 1));

    if (copy == NULL)
        return (NULL);

    /* copy string */
    for (i = 0; i <= len; i++)
        copy[i] = str[i];

    return (copy);
}
