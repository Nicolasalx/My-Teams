/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_swap
*/

#include <stddef.h>
#include "my_bitshift.h"

void my_swap(void *data_1, void *data_2, size_t size)
{
    unsigned char data[8];

    my_memcpy(data, data_1, size);
    my_memcpy(data_1, data_2, size);
    my_memcpy(data_2, data, size);
}
