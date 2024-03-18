/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** free_all_alloc
*/

#include "my_linkedlist.h"
#include "internal/my_container.h"
#include <stdlib.h>

void free_all_alloc(void)
{
    node_t *current = head_alloc;

    if (head_alloc == NULL) {
        return;
    }
    do {
        for (int i = 0; i < SIZE_CONTAINER; ++i) {
            free(GET_DATA(current, alloc_t)->data[i]);
        }
        current = current->next;
    } while (current != head_alloc);
    free_all_container(&head_alloc);
    current_reg = SIZE_CONTAINER;
    free_all_alloc_call = true;
}
