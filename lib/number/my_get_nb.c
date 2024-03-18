/*
** EPITECH PROJECT, 2024
** my_get_nb
** File description:
** my_get_nb
*/

#include "my_string.h"
#include <stdbool.h>
#include "my_char.h"

int my_get_nb(const char *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ') {
        ++i;
    }
    if (str[i] == '-') {
        sign = -1;
        ++i;
    }
    for (; str[i] != '\0'; ++i) {
        if (is_digit(str[i]) == true) {
            nb = (nb * 10) + (str[i] - '0');
        } else {
            return sign * nb;
        }
    }
    return sign * nb;
}
