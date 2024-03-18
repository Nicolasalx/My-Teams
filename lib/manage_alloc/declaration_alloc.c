/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** declaration_alloc
*/

#include "internal/my_container.h"
#include "my_linkedlist.h"
#include <stdlib.h>

node_t *head_alloc = {NULL};
size_t current_reg = SIZE_CONTAINER;
bool free_all_alloc_call = {false};
