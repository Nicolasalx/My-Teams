/*
** EPITECH PROJECT, 2024
** my_str_to_word_wm
** File description:
** my_str_to_word_wm
*/

#include "my_string.h"
#include "my_malloc.h"
#include <stdlib.h>

char **my_str_to_word_wm(const char *str, bool (*method)(char),
    int nb_word, const int *size_word)
{
    char **word = malloc_adv_board(nb_word, size_word);
    int i_index = 0;
    int j_index = 0;
    bool end_word = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (method(str[i]) == false) {
            word[i_index][j_index] = str[i];
            ++ j_index;
            end_word = true;
        } else if (end_word) {
            end_word = false;
            ++ i_index;
            j_index = 0;
        }
    }
    return word;
}
