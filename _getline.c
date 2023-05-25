#include "shell.h"

/**
 * get_line - stores commamd into malloced buffer
 * @str: buffer
 * Return: number of characters read
 */
size_t get_line(char **str)
{
	ssize_t i = 0, bytes_read = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';

		for (n = 0; buff[n] != '\0'; n++)
        {
            if (buff[n] == '\n')
                t2 = 1;
        }

		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			bytes_read = i;
			t = 1;
		}
		else
		{
			bytes_read += i;
			*str = _strcat(*str, buff);
		}
	}
	return (bytes_read);
}
