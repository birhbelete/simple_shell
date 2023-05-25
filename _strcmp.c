#include "shell.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: int that tells num spaces in between, 0 if exactly the same string
 */

int _strcmp(char* s1, char* s2)
{
	int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
    {
        if (s2[i] == '\0')
            return 0;
    }

    return (s1[i] - s2[i]);
}

