/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** print_fatal_error_and_exit
*/

#include "my_error.h"
#include "my_def.h"
#include "stdio.h"

void print_fatal_error_and_exit(int error)
{
    if (error >= 0 && error < size_error_info) {
        printf("Fatal error: \e[91m%s\e[0m\n", error_info[error].message);
    } else {
        printf("Unnamed error\n");
    }
    my_exit(error_info[error].return_value);
}
