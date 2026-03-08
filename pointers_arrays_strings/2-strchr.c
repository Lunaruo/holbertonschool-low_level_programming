#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: character to search for
 *
 * Description: This function searches for the first occurrence
 * of the character c in the string s, including the terminating
 * null byte ('\0'). If the character is found, a pointer to the
 * first occurrence of the character in the string is returned.
 * If the character is not found, the function returns NULL.
 *
 * Return: pointer to the first occurrence of c in s, or NULL
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
		i++;
	}

	if (s[i] == c)
	{
		return (&s[i]);
	}

	return (0);
}
