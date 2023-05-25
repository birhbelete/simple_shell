#include "shell.h"

/**
 * t_strlen - returns token's length
 * @str: token
 * @pos: index position in user's command typed into shell
 * @delm: delimeter 
 * Return: token length
 */
int t_strlen(char *str, int pos, char delm)
{
    int len = 0;

    for (; (str[pos] != delm) && (str[pos] != '\0'); pos++, len++)
    {
		;
    }

    return len;
}


/**
 * t_size - returns delims no ignoring continuous delim
 * @str: user's command
 * @delm: delimeter
 * Return: number of delims
 */
int t_size(char *str, char delm)
{
    int i = 0, num_delm = 0;

    for (; str[i] != '\0'; i++)
    {
        if ((str[i] == delm) && (str[i + 1] != delm))
        {
            num_delm++;
        }
        if ((str[i] == delm) && (str[i + 1] == '\0'))
        {
            num_delm--;
        }
    }

    return num_delm;
}


/**
 * ignore_delm - returns str without preceeding delims
 * @str: string
 * @delm: delimiter (e.g. " ")
 * Return: new string (e.g. "    ls -l" --> "ls -l")
 */
char *ignore_delm(char *str, char delm)
{
    for (; *str == delm; str++)
    {
		;
    }
    
    return str;
}


/**
 * _str_tok - tokenizes command and returns an array of tokens
 * @str: user's command 
 * @delm: delimeter 
 * Return: an array of tokens
 */
char **_str_tok(char *str, char *delm)
{
    int size = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
    char **tokens = NULL, delim_char;

    delim_char = delm[0];

    str = ignore_delm(str, delim_char);

    size = t_size(str, delim_char);
    tokens = malloc(sizeof(char *) * (size + 2));
    if (tokens == NULL)
        return NULL;

    while (str[se] != '\0')
        se++;

    while (si < se)
    {
        if (str[si] != delim_char)
        {
            len = t_strlen(str, si, delim_char);
            tokens[p] = malloc(sizeof(char) * (len + 1));
            if (tokens[p] == NULL)
                return NULL;

            i = 0;
            while ((str[si] != delim_char) && (str[si] != '\0'))
            {
                tokens[p][i] = str[si];
                i++;
                si++;
            }
            tokens[p][i] = '\0';
            t++;
        }

        if (si < se && (str[si + 1] != delim_char && str[si + 1] != '\0'))
            p++;

        si++;
    }

    p++;
    tokens[p] = NULL;
    return tokens;
}

