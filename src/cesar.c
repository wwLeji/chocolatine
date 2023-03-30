/*
** EPITECH PROJECT, 2023
** DUO_STUMPER
** File description:
** cesar
*/

#include "stumper.h"

static int change_shift(int shift)
{
    int mod = 0;
    int neg = 0;
    if (shift < 0) {
        shift = shift * (-1);
        neg = 1;
    }
    while (shift >= 26) {
        mod = shift % 26;
        if (mod >= 0)
            shift -= 26;
    }
    if (neg == 1)
        shift = shift * (-1);
    return (shift);
}

static char check(char c)
{
    if (c < 0) {
        c += 26;
    }
    return (c);
}

static char for_maj(char test, char c, int shift)
{
    if (test >= 'A' && test <= 'Z') {
        c = test - 'A';
        c += shift;
        c = check(c);
        c = c % 26;
        test = c + 'A';
    }
    return test;
}

static char for_min(char test, char c, int shift)
{
    if (test >= 'a' && test <= 'z') {
        c = test - 'a';
        c += shift;
        c = check(c);
        c = c % 26;
        test = c + 'a';
    }
    return test;
}

int cesar(char *str, int shift)
{
    char c = 0;
    shift = change_shift(shift);
    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = for_maj(str[i], c, shift);
        str[i] = for_min(str[i], c, shift);
    }
    if (write_in_file(str) == -1)
        return -1;
    return (0);
}
