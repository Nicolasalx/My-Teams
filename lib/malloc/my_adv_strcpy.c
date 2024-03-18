/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_adv_strcpy
*/

#include "my_malloc.h"
#include <stdlib.h>

char *my_adv_strcpy(char *dest, const char *src)
{
    char *new_str = my_strdup(src);

    if (dest != NULL) {
        my_free(dest);
    }
    return new_str;
}
