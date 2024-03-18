/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_put_double
*/

#include "my_number.h"
#include "my_string.h"

void my_put_double(double nb, int precision)
{
    int int_part = (int) nb;
    double decimal = nb - int_part;
    int decimal_part;

    decimal *= my_pow(10, precision);
    decimal_part = (int) (my_abs(decimal) + 0.5);
    my_put_nb(int_part);
    if (precision > 0) {
        my_putchar('.');
        my_put_nb(decimal_part);
    }
}
