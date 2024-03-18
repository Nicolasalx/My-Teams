/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_strdup
*/

#include "my_string.h"
#include "my_malloc.h"

char *my_strdup(const char *str)
{
    char *new_str = malloc_str(strlen(str));

    my_strcpy(new_str, str);
    return new_str;
}
