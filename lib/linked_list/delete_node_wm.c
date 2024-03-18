/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** delete_node_with_method
*/

#include "my_malloc.h"
#include "my_linkedlist.h"
#include <stdlib.h>

void delete_node_wm(node_t **head, node_t *node, void (*method)(void *))
{
    if (*head == NULL || node == NULL) {
        return;
    }
    if (*head == node) {
        *head = node->next;
    }
    if (node->next == node && node->prev == node) {
        *head = NULL;
        method(node->data);
        my_free(node);
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    method(node->data);
    my_free(node);
}
