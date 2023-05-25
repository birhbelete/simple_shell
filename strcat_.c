#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: destination string
 * @src: src string
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int t = 0;
	int z = 0;

	/* find total length of both strings to _realloc */
	for (; dest[i] != '\0'; i++)
		t++;

	for (; src[j] != '\0'; j++)
		t++;

	/* _realloc because dest was malloced outside of function */
	dest = _realloc(dest, i, sizeof(char) * (t + 1));

	for (; src[z] != '\0'; i++, z++)
		dest[i] = src[z];

	dest[i] = '\0';

	return (dest);
}

