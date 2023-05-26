#include "shell.h"

/**
 * c_ignore - ignores spaces and newlines
 * @str: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * non_interactive - handles piped commands
 * @env: envrionmental variables
 */
void non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int cmd_line_no = 0, exit_stat = 0;
	char *cmd = NULL, *n_cmd = NULL, **n_line, **token;

	i = get_line(&cmd);
	if (i == 0)
	{
		free(cmd);
		exit(0);
	}
	n_cmd = cmd;
	cmd = c_ignore(cmd);
	n_line = _str_tok(cmd, "\n");
	if (n_cmd != NULL)
		free(n_cmd);
	n = 0;
	while (n_line[n] != NULL)
	{
		cmd_line_no++;
		token = NULL;
		token = _str_tok(n_line[n], " ");
		exit_stat = built_in(token, env, cmd_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execve(token, env, cmd_line_no);
		n++;
	}
	free_array(n_line);
	free_linked_list(env);
	exit(exit_stat);
}
