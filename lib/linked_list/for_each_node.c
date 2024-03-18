/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** for_each_node
*/

#include "my_linkedlist.h"
#include <stdlib.h>

void for_each_node(node_t *head, void (*method)(node_t *))
{
    node_t *current = head;

    if (head == NULL) {
        return;
    }
    do {
        method(current);
        current = current->next;
    } while (current != head);
}
