#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, list_t *env)
{
    char *path, *cncat = NULL, **tokens;
    int i = 0;

    path = get_env("PATH", env);
    tokens = c_str_tok(path, ":");
    free(path);

    i = 0;
    while (tokens[i] != NULL)
    {
        if (tokens[i][0] == '\0')
            cncat = getcwd(cncat, 0);
        else
            cncat = _strdup(tokens[i]);
        
        cncat = _strcat(cncat, "/");
        cncat = _strcat(cncat, str);

        if (access(cncat, F_OK) == 0)
        {
            free_array(tokens);
            return cncat;
        }

        free(cncat);
        i++;
    }

    free_array(tokens);
    return str;
}

