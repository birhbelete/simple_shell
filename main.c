#include "shell.h"

/**
 * main - main entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environmental variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	shell(env);

	return (0);
}
