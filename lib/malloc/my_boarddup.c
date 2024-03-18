/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_boarddup
*/

#include "my_malloc.h"
#include "my_string.h"
#include <stdlib.h>

char **my_boarddup(char **board)
{
    char **new_board = my_malloc(sizeof(char *) * (my_boardlen(board) + 1));
    int i = 0;

    for (; board[i] != NULL; ++i) {
        new_board[i] = my_strdup(board[i]);
    }
    new_board[i] = NULL;
    return new_board;
}
