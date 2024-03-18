/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_put_fd
*/

#include <unistd.h>
#include "my_string.h"

void my_put_fd(int fd, char *str)
{
    write(fd, str, strlen(str));
}
