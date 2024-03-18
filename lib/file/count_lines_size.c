/*
** EPITECH PROJECT, 2024
** count_lines_size
** File description:
** count_lines_size
*/

#include "my_malloc.h"
#include "my_error.h"
#include <stdlib.h>

int *count_lines_size(const char *str, int nb_line)
{
    int *lines_size = my_malloc(sizeof(int) * nb_line);
    int count_lines_size = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != '\n') {
            ++ count_lines_size;
        } else {
            lines_size[j] = count_lines_size;
            ++ j;
            count_lines_size = 0;
        }
    }
    if (j < nb_line) {
        lines_size[j] = count_lines_size;
    }
    return lines_size;
}
