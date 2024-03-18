/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_put_bool
*/

#include "my_string.h"

void my_put_bool(bool value)
{
    if (value == false) {
        my_putstr("false");
    } else {
        my_putstr("true");
    }
}
