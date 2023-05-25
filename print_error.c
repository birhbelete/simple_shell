#include "shell.h"

/**
 * cant_cd_to - write error ("sh: 2: cd: can't cd to xyz")
 * @str: user's typed argument after the cmd cd
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void cant_cd_to(char *str, int c_n, list_t *env)
{
	int i;
	char *shell, *num;

	shell = get_env("_", env);
	for (i = 0; shell[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, shell, i);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	for (i = 0; num[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, num, i);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	for (i = 0; str[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, str, i);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * not_found - write error eg"sh: 1: lss: not found"
 * @str: command
 * @c_n: nth user's  command
 * @env: environmental variables linked list to write shell name
 */

void not_found(char *str, int cmd_no, list_t *env)
{
	int i;
	char *shell, *num;

	shell = get_env("_", env);
	for (i = 0; shell[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, shell, i);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(cmd_no);
	for (i = 0; num[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, num, i);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	for (i = 0; str[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, str, i);
	write(STDOUT_FILENO, ": not found\n", 12);
}



/**
 * illegal_number - write error ("sh: 3: exit: Illegal number abc (or -1)")
 * @str: user's typed argument after the cmd exit
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void illegal_number(char *str, int c_n, list_t *env)
{
	int i;
	char *shell, *num;

	shell = get_env("_", env);
	for (i = 0; shell[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, shell, i);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	for (i = 0; num[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, num, i);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	for (i = 0; str[i] != '\0'; i++)
		;
	write(STDOUT_FILENO, str, i);
	write(STDOUT_FILENO, "\n", 1);
}

