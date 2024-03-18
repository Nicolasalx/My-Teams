/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** to_lower
*/

#include "my_char.h"

char *to_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_upper(str[i])) {
            str[i] += 32;
        }
    }
    return str;
}
