#include "shell.h"

/**
 **_strncpy - Copies string
 *@dest: Destination string to be copied to
 *@src: Source string
 *@n: Amount of characters copied
 *Return: Concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - Concatenates two strings
 *@dest: First string
 *@src: Second string
 *@n: Amount of bytes to be maximally used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, p;
	char *s = dest;

	a = 0;
	p = 0;
	while (dest[a] != '\0')
		a++;
	while (src[p] != '\0' && p < n)
	{
		dest[a] = src[p];
		a++;
		p++;
	}
	if (p < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - Locates character in string
 *@s: String to be parsed
 *@c: Character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
