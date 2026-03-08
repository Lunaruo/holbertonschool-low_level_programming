#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to locate
 *
 * Description: This function finds the first occurrence
 * of the substring needle in the string haystack. The
 * terminating null bytes are not compared.
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		i = 0;

		while (needle[i] && haystack[i] == needle[i])
			i++;

		if (!needle[i])
			return (haystack);

		haystack++;
	}

	return (NULL);
}
