/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_calloc
*/

#include "my_malloc.h"
#include "my_bitshift.h"

void *my_calloc(size_t size)
{
    return my_memset(my_malloc(size), 0, size);
}
