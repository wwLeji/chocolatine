/*
** EPITECH PROJECT, 2023
** EXEMPLE
** File description:
** stumper
*/

#ifndef STUMPER_H_
    #define STUMPER_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int help(void);
    int cesar(char *str, int shift);
    char* get_text_in_file(const char *file_name);
    int write_in_file(const char* str);
    int check_args(const int argc, char *const *const argv);
    int error_handling(int argc);

#endif /* !STUMPER_H_ */
