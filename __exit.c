#include "shell.h"

/**
 * __exit - frees user commamd and then exits 
 * @str: user's command into shell
 * @env: bring in environmental variable to free at error
 * @num: bring in nth user command line input to print in error message
 * @command: bring in command to free
 * Return: 0 if success 2 if fail
 */

int __exit(char **str, list_t *env, int num, char **command)
{
	int e_ = 0;

	if (str[1] != NULL)
		e_ = c_atoi(str[1]);

	if (e_ == -1)
	{
		illegal_number(str[1], num, env);
		free_array(str);
		return (2);
	}
	free_array(str);
	free_linked_list(env);
	if (command != NULL)
		free_array(command);
	exit(e_);
}
