/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** create_container
*/

#include "my_linkedlist.h"
#include "my_managealloc.h"
#include "internal/my_container.h"
#include "my_error.h"
#include "my_bitshift.h"
#include <stdlib.h>

node_t *create_container(void)
{
    node_t *container;

    container = malloc(sizeof(node_t));
    if (container == NULL) {
        free_all_alloc();
        print_fatal_error_and_exit(MALLOC_FAIL);
    }
    container->data = malloc(sizeof(alloc_t));
    if (container->data == NULL) {
        free_all_alloc();
        print_fatal_error_and_exit(MALLOC_FAIL);
    }
    my_memset(container->data, 0, sizeof(alloc_t));
    return container;
}
