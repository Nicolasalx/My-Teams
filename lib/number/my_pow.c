/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_pow
*/

#include "my_number.h"

double my_pow(double nb, int power)
{
    double result = 1;
    int abs_power = my_abs(power);

    while (abs_power > 0) {
        result *= nb;
        -- abs_power;
    }
    if (power < 0) {
        result = 1.0 / result;
    }
    return result;
}
