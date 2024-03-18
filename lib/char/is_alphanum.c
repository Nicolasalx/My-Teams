/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** is_alphanum
*/

#include <stdbool.h>

bool is_alphanum(char c)
{
    return ((65 <= c && c <= 90)
        || (97 <= c && c <= 122)
        || (48 <= c && c <= 57));
}
