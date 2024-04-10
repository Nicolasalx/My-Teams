/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** exec_command_parsing
*/

#include "myteams_client.h"
#include "command_list.h"

int count_nb_word_quotes(const char *str)
{
    int result = 0;
    bool is_in_quote = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\"') {
            is_in_quote = !is_in_quote;
            ++result;
        }
    }
    if (result % 2 != 0) {
        return -1;
    }
    return result / 2;
}

void count_size_word_opt(bool *is_in_quotes,
    int **size_word, int *index, int *count_size_word)
{
    if (*is_in_quotes) {
        (*size_word)[*index] = *count_size_word;
        *is_in_quotes = false;
        ++*index;
        *count_size_word = 0;
    } else {
        *is_in_quotes = true;
    }
}

int *count_size_word_quotes(int nb_word,
    char *delimiter, const char *str)
{
    int *size_word = malloc_array(nb_word);
    int count_size_word = 0;
    int index = 0;
    bool is_in_quotes = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter)) {
            count_size_word_opt(&is_in_quotes,
                &size_word, &index, &count_size_word);
            continue;
        }
        if (is_in_quotes) {
            ++count_size_word;
        }
    }
    return size_word;
}

void my_str_to_word_opt(bool *is_in_quotes, int *i_index, int *j_index)
{
    if (*is_in_quotes) {
        ++*i_index;
        *j_index = 0;
        *is_in_quotes = false;
    } else {
        *is_in_quotes = true;
    }
}

char **my_str_to_word_quotes(int nb_word, int *size_word,
    char *delimiter, const char *str)
{
    char **word = malloc_adv_board(nb_word, size_word);
    int i_index = 0;
    int j_index = 0;
    bool is_in_quotes = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter)) {
            my_str_to_word_opt(&is_in_quotes, &i_index, &j_index);
            continue;
        }
        if (is_in_quotes) {
            word[i_index][j_index] = str[i];
            ++j_index;
        }
    }
    return word;
}
