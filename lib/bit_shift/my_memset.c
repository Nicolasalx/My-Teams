/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_memset
*/

#include <stddef.h>

void *my_memset(void *data, int value, size_t size)
{
    unsigned char *ptr = data;

    for (; size > 0; --size) {
        *ptr = value;
        ++ ptr;
    }
    return data;
}
