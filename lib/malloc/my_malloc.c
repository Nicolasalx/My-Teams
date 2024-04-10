/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_malloc
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_error.h"
#include "my_managealloc.h"
#include "my_bitshift.h"

void *my_malloc(size_t size)
{
    void *data;

    if (size == 0) {
        return NULL;
    }
    data = malloc(size + sizeof(void *));
    if (data == NULL) {
        free_all_alloc();
        print_fatal_error_and_exit(MALLOC_FAIL);
    }
    my_memcpy(data, &(const void *) {register_alloc(data)}, sizeof(void *));
    data += sizeof(void *);
    return data;
}
