/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** build_str
*/

#include <stdarg.h>
#include "my_string.h"
#include "my_bitshift.h"

char *build_str(char *dest, int nb_str, ...)
{
    va_list arg;

    va_start(arg, nb_str);
    for (int i = 0; i < nb_str; ++i) {
        my_strcat(dest, va_arg(arg, char *));
    }
    va_end(arg);
    return dest;
}
