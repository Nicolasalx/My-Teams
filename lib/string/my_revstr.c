/*
** EPITECH PROJECT, 2024
** my_strrev
** File description:
** my_strrev
*/

#include "my_string.h"
#include "my_bitshift.h"

char *my_revstr(char *str)
{
    int j = (strlen(str) - 1);

    for (int i = 0; i < j; ++i) {
        my_swap(&str[i], &str[j], sizeof(char));
        -- j;
    }
    return str;
}
