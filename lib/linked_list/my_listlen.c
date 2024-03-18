/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-dante-thibaud.cathala
** File description:
** my_listlen
*/

#include "my_linkedlist.h"
#include <stdlib.h>

int my_listlen(const node_t *head)
{
    int i = 1;
    const node_t *current = head;

    if (head == NULL) {
        return 0;
    }
    current = current->next;
    while (current != head) {
        current = current->next;
        ++ i;
    }
    return i;
}
