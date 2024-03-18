/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_put_x_fd
*/

#include <unistd.h>
#include <stdarg.h>
#include "my_string.h"

void my_put_fd_fm(int fd, int nb_str, ...)
{
    char *str;
    va_list arg;

    va_start(arg, nb_str);
    for (int i = 0; i < nb_str; ++i) {
        str = va_arg(arg, char *);
        write(fd, str, strlen(str));
    }
    va_end(arg);
}
