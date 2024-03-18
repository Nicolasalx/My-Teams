/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-dante-thibaud.cathala
** File description:
** create_new_node
*/

#include "my_linkedlist.h"
#include <stdlib.h>
#include "my_malloc.h"

node_t *create_node(void *data)
{
    node_t *new_node = my_malloc(sizeof(node_t));

    new_node->data = data;
    return new_node;
}
