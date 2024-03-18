/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_double_to_str
*/

#include "my_string.h"
#include "my_number.h"
#include "my_bitshift.h"

char *my_double_to_str(double nb, int precision, char *str)
{
    char str_int[INT_STR_SIZE] = {0};
    int int_part = (int) nb;
    double decimal = nb - int_part;
    int decimal_part;

    my_memset(str, 0, DOUBLE_STR_SIZE);
    decimal *= my_pow(10, precision);
    decimal_part = (int) (my_abs(decimal) + 0.5);
    my_strcpy(str, my_nb_to_str(int_part, str_int));
    if (precision > 0) {
        my_strcat(str, ".");
        my_strcat(str, my_nb_to_str(decimal_part, str_int));
    }
    return str;
}
