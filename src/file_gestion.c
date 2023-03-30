/*
** EPITECH PROJECT, 2023
** file gestion
** File description:
** file gestion
*/

#include "stumper.h"

int write_in_file (const char *str)
{
    FILE *file = fopen("crypt", "wr");
    if (file == NULL)
        return -1;
    if (fprintf(file, "%s", str) < 0)
        return -1;
    fclose (file);
    return (0);
}

char *get_text_in_file (const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    char *text = NULL;
    size_t len = 0;
    size_t read = 0;
    if (file_name == NULL)
        return (NULL);
    if (file == NULL)
        return (NULL);
    while ((int) (read = getline (&text, &len, file)) != -1);
    fclose(file);
    return (text);
}
