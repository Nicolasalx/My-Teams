/*
** EPITECH PROJECT, 2024
** my_open_file
** File description:
** my_open_file
*/

#include <fcntl.h>

int open_file(const char *filepath)
{
    return open(filepath, O_RDONLY);
}
