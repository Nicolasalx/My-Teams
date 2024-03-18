/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** count_nb_word_wm
*/

#include "my_string.h"

int count_nb_word_wm(const char *str, bool (*method)(char))
{
    int count_word = 0;
    bool already_count = false;
    bool is_delimiter = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        is_delimiter = method(str[i]);
        if (is_delimiter == false && already_count == false) {
            ++ count_word;
            already_count = true;
        }
        if (is_delimiter) {
            already_count = false;
        }
    }
    return count_word;
}
