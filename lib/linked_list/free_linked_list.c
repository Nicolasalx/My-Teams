/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** free_linked_list
*/

#include "my_malloc.h"
#include "my_linkedlist.h"
#include <stdlib.h>

void free_linked_list(node_t **head)
{
    node_t *current;
    node_t *next;

    if (*head == NULL) {
        return;
    }
    current = (*head)->next;
    while (current != *head) {
        next = current->next;
        my_free(current->data);
        my_free(current);
        current = next;
    }
    my_free((*head)->data);
    my_free(*head);
    *head = NULL;
}
