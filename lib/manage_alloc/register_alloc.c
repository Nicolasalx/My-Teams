/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** register_alloc
*/

#include "my_malloc.h"
#include "my_linkedlist.h"
#include "internal/my_container.h"
#include <stddef.h>

void *register_alloc(void *data)
{
    if (current_reg >= SIZE_CONTAINER) {
        current_reg = 0;
        append_node(&head_alloc, create_container());
    }
    GET_DATA(head_alloc->prev, alloc_t)->data[current_reg] = data;
    ++ current_reg;
    return &GET_DATA(head_alloc->prev, alloc_t)->data[current_reg - 1];
}
