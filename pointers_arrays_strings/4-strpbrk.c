#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to be searched
 * @accept: bytes to search for
 *
 * Description: This function locates the first occurrence
 * in the string s of any of the bytes from the string accept.
 * If a matching byte is found, a pointer to that byte in s
 * is returned. If no match is found, NULL is returned.
 *
 * Return: pointer to the matching byte in s, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
