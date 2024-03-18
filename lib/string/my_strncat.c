/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_strncat
*/

#include "my_string.h"
#include <stddef.h>

char *my_strncat(char *dest, const char *src, size_t n)
{
    int size_dest = strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; ++i) {
        dest[i + size_dest] = src[i];
    }
    dest[i + size_dest] = '\0';
    return dest;
}
