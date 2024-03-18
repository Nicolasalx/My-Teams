/*
** EPITECH PROJECT, 2024
** adv_board
** File description:
** adv_board
*/

#include "my_malloc.h"

char **malloc_adv_board(int nb_line, const int *size_line)
{
    char **board = my_malloc(sizeof(char *) * (nb_line + 1));
    int i;

    for (i = 0; i < nb_line; ++i) {
        board[i] = my_malloc(sizeof(char) * (size_line[i] + 1));
        board[i][size_line[i]] = '\0';
    }
    board[i] = NULL;
    return board;
}
