/*
** EPITECH PROJECT, 2024
** my_put_board
** File description:
** my_put_board
*/

#include "my_string.h"
#include <stdlib.h>

void my_putboard(char **board, const char *separator, const char *last_char)
{
    for (int i = 0; board[i] != NULL; ++i) {
        my_putstr(board[i]);
        if (board[i + 1] != NULL) {
            my_putstr(separator);
        } else {
            my_putstr(last_char);
        }
    }
}
