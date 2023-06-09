#include "shell.h"

/**
 * free_array - free malloced arrays
 * @str: array of strings
 */
void free_array(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}

	free(str);
}

