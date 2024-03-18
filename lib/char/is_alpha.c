/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** is_alpha
*/

#include <stdbool.h>

bool is_alpha(char c)
{
    return ((65 <= c && c <= 90)
        || (97 <= c && c <= 122));
}
