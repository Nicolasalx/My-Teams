/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** free_all_container
*/

#include "my_linkedlist.h"
#include <stdlib.h>

void free_all_container(node_t **head)
{
    node_t *current;
    node_t *next;

    if (*head == NULL) {
        return;
    }
    current = (*head)->next;
    while (current != *head) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free((*head)->data);
    free(*head);
    *head = NULL;
}
