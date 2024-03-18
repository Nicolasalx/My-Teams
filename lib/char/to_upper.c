/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** to_upper
*/

#include "my_char.h"

char *to_upper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_lower(str[i])) {
            str[i] -= 32;
        }
    }
    return str;
}
