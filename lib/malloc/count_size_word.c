/*
** EPITECH PROJECT, 2024
** count_size_word
** File description:
** count_size_word
*/

#include "my_string.h"
#include "my_malloc.h"

int *count_size_word(const char *str, const char *delimiter, int nb_word)
{
    int *size_word = malloc_array(nb_word);
    int count_size_word = 0;
    bool end_word = false;
    int index = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter) == false) {
            ++ count_size_word;
            end_word = true;
        } else if (end_word) {
            end_word = false;
            size_word[index] = count_size_word;
            ++ index;
            count_size_word = 0;
        }
    }
    if (end_word) {
        size_word[index] = count_size_word;
    }
    return size_word;
}
