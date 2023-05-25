#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string in allocated memory
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	for (len = 0; *(str + len); len++)
		;

	len++;

	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		duplicate_str[i] = str[i];

	return (duplicate_str);
}

