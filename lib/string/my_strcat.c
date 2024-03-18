/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** my_strcat
*/

#include "my_string.h"

char *my_strcat(char *dest, const char *src)
{
    int size_dest = strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; ++i) {
        dest[i + size_dest] = src[i];
    }
    dest[i + size_dest] = '\0';
    return dest;
}
