/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_memcpy
*/

#include <stddef.h>

void my_memcpy(void *dest, const void *src, size_t size)
{
    unsigned char *dest_ptr = dest;
    const unsigned char *src_ptr = src;

    for (size_t i = 0; i < size; ++i) {
        dest_ptr[i] = src_ptr[i];
    }
}
