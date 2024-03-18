/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_append
*/

#include "my_linkedlist.h"
#include "my_malloc.h"
#include <stdlib.h>

void append_node(node_t **head, node_t *node)
{
    node_t *tail;

    if (*head == NULL) {
        *head = node;
        node->next = node;
        node->prev = node;
        return;
    }
    tail = (*head)->prev;
    tail->next = node;
    node->prev = tail;
    node->next = *head;
    (*head)->prev = node;
}
