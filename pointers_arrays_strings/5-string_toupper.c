#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: string to modify
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		/* si c'est une lettre minuscule */
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - ('a' - 'A'); /* convertir en majuscule */
		}
		i++;
	}

	return (str);
}
