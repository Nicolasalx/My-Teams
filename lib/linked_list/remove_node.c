/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-dante-thibaud.cathala
** File description:
** remove_node
*/

#include "my_linkedlist.h"
#include <stdlib.h>

node_t *remove_node(node_t **head, node_t *node)
{
    if (*head == NULL || node == NULL) {
        return NULL;
    }
    if (*head == node) {
        *head = node->next;
    }
    if (node->next == node && node->prev == node) {
        *head = NULL;
        node->next = NULL;
        node->prev = NULL;
        return node;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
