/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** my_putstr
*/

#include "my_string.h"
#include <unistd.h>

void my_putstr(const char *str)
{
    write(1, str, strlen(str));
}
