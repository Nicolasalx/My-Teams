/*
** EPITECH PROJECT, 2024
** my_nb_to_str
** File description:
** my_nb_to_str
*/

#include "my_string.h"
#include "my_number.h"
#include "my_bitshift.h"

char *my_nb_to_str(int nb, char *str)
{
    int i = count_nb_digit(nb) - 1;

    my_memset(str, 0, INT_STR_SIZE);
    if (nb == MIN_INT) {
        my_strcpy(str, "-2147483648");
        return str;
    }
    if (nb == 0) {
        my_strcpy(str, "0");
        return str;
    }
    if (nb < 0) {
        str[0] = '-';
        nb = -nb;
    }
    for (; nb > 0; --i) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    return str;
}
