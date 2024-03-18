/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_bool_to_str
*/

#include "my_number.h"
#include "my_string.h"
#include "my_bitshift.h"

char *my_bool_to_str(bool value, char *str)
{
    my_memset(str, 0, BOOL_STR_SIZE);
    if (value == false) {
        my_strcpy(str, "false");
    } else {
        my_strcpy(str, "true");
    }
    return str;
}
