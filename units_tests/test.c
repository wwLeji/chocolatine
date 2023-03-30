/*
** EPITECH PROJECT, 2023
** chocolatine
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "stumper.h"

Test(test_error_handling, test_if_error_is_neg) {
    cr_assert_eq(error_handling(4), 0);
    cr_assert_eq(error_handling(3), -1);
    cr_assert_eq(error_handling(5), -1);
}
