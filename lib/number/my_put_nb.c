/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_put_nb
*/

#include "my_string.h"
#include "my_number.h"

void my_put_nb(int nb)
{
    char str[12] = {0};
    int i = count_nb_digit(nb) - 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb == 0) {
        str[0] = '0';
    }
    if (nb < 0) {
        str[0] = '-';
        nb = -nb;
    }
    for (; nb > 0; --i) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    my_putstr(str);
}
