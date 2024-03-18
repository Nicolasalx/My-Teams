/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** adv_strcat
*/

#include "my_string.h"
#include "my_malloc.h"
#include <stdlib.h>

char *my_adv_strcat(char *dest, const char *src)
{
    int size_dest = strlen(dest);
    char *new_str = malloc_str(size_dest + strlen(src));
    int i;

    my_strcpy(new_str, dest);
    my_free(dest);
    for (i = 0; src[i] != '\0'; ++i) {
        new_str[i + size_dest] = src[i];
    }
    new_str[i + size_dest] = '\0';
    return new_str;
}
