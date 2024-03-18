/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** free_linked_list_with_method
*/

#include "my_malloc.h"
#include "my_linkedlist.h"
#include <stdlib.h>

void free_linked_list_wm(node_t **head, void (*method)(void *))
{
    node_t *current;
    node_t *next;

    if (*head == NULL) {
        return;
    }
    current = (*head)->next;
    while (current != *head) {
        next = current->next;
        method(current->data);
        my_free(current);
        current = next;
    }
    method((*head)->data);
    my_free(*head);
    *head = NULL;
}
