/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** force_register_alloc
*/

#include "my_malloc.h"
#include "my_bitshift.h"
#include <stdlib.h>

void force_register_alloc(void **data, size_t size)
{
    void *data_cpy;

    data_cpy = my_malloc(size);
    my_memcpy(data_cpy, *data, size);
    free(*data);
    *data = data_cpy;
}
