/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** shift_str_to_left
*/

#include "my_string.h"

void shift_str_to_left(char *str, int nb_shift)
{
    int size_str = strlen(str);

    for (int i = 0; (i + nb_shift) < size_str; ++i) {
        str[i] = str[i + nb_shift];
    }
    for (int j = 0; j < nb_shift && ((size_str - 1) - j) >= 0; ++j) {
        str[(size_str - 1) - j] = '\0';
    }
}
