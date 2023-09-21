#include "shell.h"
#include "string_functions.h"  // Assuming string manipulation functions are in this header.

/**
 * clear_info - Initializes info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = 0;
}

/**
 * set_info - Initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
    int i = 0;

    info->fname = av[0];
    if (info->arg)
    {
        info->argv = strtow(info->arg, " \t");  // Assuming strtow exists in the string_functions.h
        if (!info->argv)
        {
            info->argv = malloc(sizeof(char *) * 2);
            if (info->argv)
            {
                info->argv[0] = strdup(info->arg); // Assuming strdup exists.
                info->argv[1] = NULL;
            }
        }
        for (i = 0; info->argv && info->argv[i]; i++)
            ;
        info->argc = i;

        // Replace alias and variables here if those functions exist.
    }
}

/**
 * free_info - Frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
    free(info->argv);
    info->argv = NULL;
    free(info->path); // Assuming path is allocated using malloc.
    info->path = NULL;
    if (all)
    {
        if (!info->cmd_buf)
            free(info->arg);
        // Free other fields if needed.
        // You should also handle freeing info->environ, info->cmd_buf, and info->readfd as needed.
        if (info->readfd > 2)
            close(info->readfd);
    }
}
