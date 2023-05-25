#include "shell.h"

/**
 * shell - executes the shell process
 * @en: envrionmental variables
 * Return: 0 on success
 */
int shell(char **en)
{
    list_t *env;
    size_t len = 0;
	size_t cmd_len;
    char *cmd, *n_cmd, **toks;
    int cmd_no = 0, exit_stat = 0;

    env = env_linked_list(en);

    do {
        cmd_no++;
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);
        else
            non_interactive(env);
        
        signal(SIGINT, ctrl_c);
        
        cmd = NULL;
        len = 0;
        len = get_line(&cmd);
        
        ctrl_D(len, cmd, env);
        
        n_cmd = cmd;
        cmd = ignore_space(cmd);

        cmd_len = 0;
        while (cmd[cmd_len] != '\n')
            cmd_len++;
        cmd[cmd_len] = '\0';

        if (cmd[0] == '\0') {
            free(n_cmd);
            continue;
        }

        toks = NULL;
        toks = _str_tok(cmd, " ");
        if (n_cmd != NULL)
            free(n_cmd);

        exit_stat = built_in(toks, env, cmd_no, NULL);
        if (exit_stat)
            continue;
        exit_stat = _execve(toks, env, cmd_no);
    } while (1);

    return exit_stat;
}

