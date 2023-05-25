#include "shell.h"

/**
 * c_exit - frees user command and linked linked then exit
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void c_exit(char **str, list_t *env)
{
	free_array(str);
	free_linked_list(env);
	_exit(0);
}