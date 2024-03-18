/*
** EPITECH PROJECT, 2024
** my_str_to_board
** File description:
** my_str_to_board
*/

#include <stdlib.h>
#include "my_malloc.h"

char **my_str_to_board(const char *str, int nb_line, const int *size_line)
{
    int i;
    int j;
    int index_str = 0;
    char **board = my_malloc(sizeof(char *) * (nb_line + 1));

    for (i = 0; i < nb_line; ++i) {
        board[i] = my_malloc(sizeof(char) * (size_line[i] + 1));
        for (j = 0; j < size_line[i]; ++j) {
            board[i][j] = str[index_str];
            ++ index_str;
        }
        board[i][j] = '\0';
        ++ index_str;
    }
    board[i] = NULL;
    return board;
}
