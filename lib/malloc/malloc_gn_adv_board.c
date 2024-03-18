/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** malloc_gn_adv_board
*/

#include "my_malloc.h"
#include <stdlib.h>

void **malloc_gn_adv_board(int nb_line, int *size_line, size_t size)
{
    void **board = my_malloc(sizeof(void *) * (nb_line + 1));
    int i;

    for (i = 0; i < nb_line; ++i) {
        board[i] = my_malloc(size * size_line[i]);
    }
    board[i] = NULL;
    return board;
}
