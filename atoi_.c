#include "shell.h"

/**
 * c_atoi - converts str to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int c_atoi(char *s)
{
	int index;
	unsigned int num = 0;

	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] >= '0' && s[index] <= '9')
			num = num * 10 + (s[index] - '0');
		if (s[index] > '9' || s[index] < '0')
			return (-1);
	}

	return (num);
}
