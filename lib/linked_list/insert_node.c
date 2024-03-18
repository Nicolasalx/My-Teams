/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** insert_node
*/

#include "my_linkedlist.h"
#include <stdlib.h>

void insert_node(node_t **head, node_t *prev_node, node_t *node)
{
    if (*head == NULL) {
        node->next = node;
        node->prev = node;
        *head = node;
    } else if (prev_node == NULL) {
        node->next = (*head);
        node->prev = (*head)->prev;
        (*head)->prev->next = node;
        (*head)->prev = node;
        *head = node;
    } else {
        node->next = prev_node->next;
        node->prev = prev_node;
        prev_node->next->prev = node;
        prev_node->next = node;
    }
}
