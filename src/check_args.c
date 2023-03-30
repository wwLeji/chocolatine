/*
** EPITECH PROJECT, 2023
** DUO_STUMPER
** File description:
** check_args
*/

#include "stumper.h"

int help(void)
{
    if (printf("Usage: ./cesar -s \"string\" \"key\"\n") < 0)
        return (-1);
    if (printf("       ./cesar -f \"file\" \"key\"\n") < 0)
        return (-1);
    return (0);
}

static int check_key(char *const key)
{
    for (int i = 0; key[i] != '\0'; i++) {
        if ((key[i] < '0' || key[i] > '9') && key[i] != '-')
            return (-1);
    }
    return (0);
}

int error_handling(int argc)
{
    if (argc != 4) {
        if (help() == -1)
            return -1;
        return -1;
    }
    return 0;
}

int check_args(const int argc, char *const *const argv)
{
    char *str = NULL;
    if (error_handling(argc) == -1)
        return -1;
    if (check_key(argv[3]) == -1)
        return (-1);
    if (strcmp(argv[1], "-s") == 0)
        if (cesar(argv[2], atoi(argv[3])) == -1)
            return (-1);
    if (strcmp(argv[1], "-f") == 0) {
        str = get_text_in_file(argv[2]);
        if (str == NULL)
            return (-1);
        if (cesar(str, atoi(argv[3])) == -1)
            return (-1);
    }
    if (strcmp(argv[1], "-h") == 0) {
        if (help() == -1)
            return (-1);
    }
    return (0);
}
