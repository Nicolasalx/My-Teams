/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** free_board
*/

#include "my_malloc.h"
#include <stdlib.h>

void free_board(void **board)
{
    if (board != NULL) {
        for (int i = 0; board[i] != NULL; ++i) {
            my_free(board[i]);
        }
        my_free(board);
    }
}
