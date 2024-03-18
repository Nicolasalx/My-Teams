/*
** EPITECH PROJECT, 2024
** str
** File description:
** malloc_a_str
*/

#include <stdlib.h>
#include "my_malloc.h"

char *malloc_str(int size_str)
{
    char *str = my_malloc(sizeof(char) * (size_str + 1));

    str[size_str] = '\0';
    return str;
}
