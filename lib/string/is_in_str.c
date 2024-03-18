/*
** EPITECH PROJECT, 2024
** is_in_str
** File description:
** is_in_str
*/

#include "my_string.h"
#include <stdbool.h>

bool is_in_str(char c, const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}
