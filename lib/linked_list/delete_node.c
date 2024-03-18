/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** delete_node
*/

#include "my_malloc.h"
#include "my_linkedlist.h"
#include <stdlib.h>

void delete_node(node_t **head, node_t *node)
{
    if (*head == NULL || node == NULL) {
        return;
    }
    if (*head == node) {
        *head = node->next;
    }
    if (node->next == node && node->prev == node) {
        *head = NULL;
        my_free(node->data);
        my_free(node);
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    my_free(node->data);
    my_free(node);
}
