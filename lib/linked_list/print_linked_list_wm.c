/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** print_linked_list_wm
*/

#include "my_linkedlist.h"
#include <stdlib.h>
#include "my_string.h"

void print_linked_list_wm(const node_t *head, void (*method)(void *),
    char *end)
{
    const node_t *current = head;

    if (head == NULL) {
        return;
    }
    do {
        method(current->data);
        current = current->next;
    } while (current != head);
    my_putstr(end);
}
