/*
** EPITECH PROJECT, 2024
** board
** File description:
** malloc_a_board
*/

#include "my_malloc.h"
#include <stdlib.h>

char **malloc_board(int nb_line, int size_line)
{
    char **board = my_malloc(sizeof(char *) * (nb_line + 1));
    int i;

    for (i = 0; i < nb_line; ++i) {
        board[i] = my_malloc(sizeof(char) * (size_line + 1));
        board[i][size_line] = '\0';
    }
    board[i] = NULL;
    return board;
}
