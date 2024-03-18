/*
** EPITECH PROJECT, 2024
** count_nb_word
** File description:
** count_nb_word
*/

#include "my_string.h"

int count_nb_word(const char *str, const char *delimiter)
{
    int count_word = 0;
    bool already_count = false;
    bool is_delimiter;

    for (int i = 0; str[i] != '\0'; ++i) {
        is_delimiter = is_in_str(str[i], delimiter);
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
