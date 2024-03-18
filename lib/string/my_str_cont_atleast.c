/*
** EPITECH PROJECT, 2024
** my_str_cont_atleast
** File description:
** my_str_cont_atleast
*/

#include "my_string.h"
#include <stdbool.h>

bool my_str_cont_atleast(const char *str, const char *characters)
{
    for (int i = 0; characters[i] != '\0'; ++i) {
        if (is_in_str(characters[i], str) == false) {
            return false;
        }
    }
    return true;
}
