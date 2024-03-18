/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** print_buffer
*/

#include "internal/my_buffer.h"
#include <unistd.h>

void print_buffer(char *str, size_t size)
{
    if (buffer_size + size >= sizeof(buffer)) {
        write(1, buffer, buffer_size);
        buffer_size = 0;
    }
    if (size > sizeof(buffer)) {
        write(1, str, size);
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        buffer[buffer_size] = str[i];
        ++ buffer_size;
    }
}
