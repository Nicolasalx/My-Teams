/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_headalloc
*/

#ifndef MY_CONTAINER_H_
    #define MY_CONTAINER_H_

    #include "my_linkedlist.h"
    #include <stddef.h>
    #include <stdbool.h>

    #define SIZE_CONTAINER 1000

typedef struct {
    void *data[SIZE_CONTAINER];
} alloc_t;

extern node_t *head_alloc;
extern size_t current_reg;

extern bool free_all_alloc_call;

node_t *create_container(void);
void free_all_container(node_t **head);

#endif /* !MY_CONTAINER_H_ */
