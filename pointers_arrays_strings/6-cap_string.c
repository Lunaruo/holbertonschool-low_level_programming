#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i = 0;

	/* Traiter le premier caractère */
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 'a' - 'A';

	/* Parcours de la chaîne */
	while (str[i] != '\0')
	{
		/* si le caractère précédent est un séparateur */
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i > 0)
			{
				switch (str[i - 1])
				{
					case ' ': case '\t': case '\n':
					case ',': case ';': case '.': case '!': case '?':
					case '"': case '(': case ')': case '{': case '}':
						str[i] -= 'a' - 'A';
						break;
				}
			}
		}
		i++;
	}

	return (str);
}
