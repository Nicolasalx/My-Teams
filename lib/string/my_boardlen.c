/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_boardlen
*/

#include <stdlib.h>

int my_boardlen(char **board)
{
    int i = 0;

    for (; board[i] != NULL; ++i);
    return i;
}
