#include "shell.h"


/**
 * c_setenv - custom _setenv by concatenating string first before setting
 * @env: environmental variable
 * @name: environmental variable name
 * @dir: directory path 
 * Return: 0 on success
 */
int c_setenv(list_t** env, char* name, char* dir)
{
    int index = 0, j = 0;
    char* cat;
    list_t* holder;

    cat = _strdup(name);
    cat = _strcat(cat, "=");
    cat = _strcat(cat, dir);
    index = find_env(*env, name);

    holder = *env;
    for (j = 0; j < index; j++)
    {
        holder = holder->next;
    }

    free(holder->var);
    holder->var = _strdup(cat);
    free(cat);
    return 0;
}

/**
 * c_strcat - concatenate two strings ignoring the first character ("~" in cd)
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char* c_strcat(char* dest, char* src)
{
    int len = 0;
    int len2 = 0;
    int total_len = 0;
    int j = 0;

    for (len = 0; dest[len] != '\0'; len++)
    {
        total_len++;
    }

    for (len2 = 0; src[len2] != '\0'; len2++)
    {
        total_len++;
    }

    dest = _realloc(dest, len, sizeof(char) * (total_len + 1));

    for (j = 1; src[j] != '\0'; j++)
    {
        dest[len] = src[j];
        len++;
    }

    dest[len] = '\0';

    return dest;
}




/**
 * cd_only - change to home directory
 * @env: environmental linked list to update PATH and OLDPWD
 * @current: current working dir
 */
void cd_only(list_t* env, char* current)
{
    char* home = get_env("HOME", env);
    c_setenv(&env, "OLDPWD", current);
    free(current);

    if (access(home, F_OK) == 0)
    {
        chdir(home);
    }

    current = NULL;
    current = getcwd(current, 0);
    c_setenv(&env, "PWD", current);
    free(current);
    free(home);
}

/**
 * cd_execute - executes cd
 * @env: environmental linked list to update PATH and OLDPWD
 * @current: current working directotry
 * @dir: dir path to change to
 * @str: 1st argument to write out error
 * @num: line number to write out error
 * Return: 0 if success 2 if fail
 */
int cd_execute(list_t* env, char* current, char* dir, char* str, int num)
{
    int i = 0;

    if (access(dir, F_OK) == 0)
    {
        c_setenv(&env, "OLDPWD", current);
        free(current);
        chdir(dir);
        current = NULL;
        current = getcwd(current, 0);
        c_setenv(&env, "PWD", current);
        free(current);
    }
    else
    {
        cant_cd_to(str, num, env);
        free(current);
        i = 2;
    }

    return i;
}


/**
 * _cd - change directory
 * @str: user's command
 * @env: enviromental linked list to get HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char** str, list_t* env, int num)
{
    char* current = NULL;
    char* dir = NULL;
    int exit_stat = 0;

    current = getcwd(current, 0);

    if (str[1] != NULL)
    {
        if (str[1][0] == '~')
        {
            dir = get_env("HOME", env);
            dir = c_strcat(dir, str[1]);
        }
        else if (str[1][0] == '-')
        {
            if (str[1][1] == '\0')
                dir = get_env("OLDPWD", env);
        }
        else
        {
            if (str[1][0] != '/')
            {
                dir = getcwd(dir, 0);
                dir = _strcat(dir, "/");
                dir = _strcat(dir, str[1]);
            }
            else
                dir = _strdup(str[1]);
        }

        exit_stat = cd_execute(env, current, dir, str[1], num);
        free(dir);
    }
    else
    {
        cd_only(env, current);
    }

    free_array(str);
    return exit_stat;
}

