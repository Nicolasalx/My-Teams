/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_exit
*/

#include "my_error.h"
#include <stdlib.h>
#include "my_managealloc.h"

void my_exit(int exit_value)
{
    free_all_alloc();
    exit(exit_value);
}
