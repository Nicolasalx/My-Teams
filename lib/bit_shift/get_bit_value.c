/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** get_bit_value
*/

#include "stdbool.h"

bool get_bit_value(unsigned char c, int index_bit)
{
    return ((c >> index_bit) & 1);
}
