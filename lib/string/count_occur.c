/*
** EPITECH PROJECT, 2024
** count_occur
** File description:
** count_occur
*/

#include "my_string.h"

int count_occur(const char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            ++count;
        }
    }
    return count;
}
