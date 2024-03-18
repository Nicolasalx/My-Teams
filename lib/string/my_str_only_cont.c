/*
** EPITECH PROJECT, 2024
** my_str_only_cont
** File description:
** my_str_only_contains
*/

#include "my_string.h"
#include <stdbool.h>

bool my_str_only_cont(const char *str, const char *characters)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], characters) == 0) {
            return false;
        }
    }
    return true;
}
