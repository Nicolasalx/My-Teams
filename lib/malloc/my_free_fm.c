/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_free
*/

#include "my_bitshift.h"
#include "internal/my_container.h"
#include <stdlib.h>

void my_free(void *data)
{
    void **register_ptr;

    if (data != NULL && free_all_alloc_call == false) {
        data -= sizeof(void *);
        my_memcpy(&register_ptr, data, sizeof(void *));
        *register_ptr = NULL;
        free(data);
    }
}
