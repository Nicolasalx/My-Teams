/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** flush_buffer
*/

#include "internal/my_buffer.h"
#include <unistd.h>

void flush_buffer(void)
{
    write(1, buffer, buffer_size);
    buffer_size = 0;
}
