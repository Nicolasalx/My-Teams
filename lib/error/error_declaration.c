/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** error_declaration
*/

#include "my_error.h"

const error_t error_info[] = {
    {NO_ERROR, "No error happened", 0},
    {MALLOC_FAIL, "Malloc fail", 84},
    {STAT_FAIL, "Stat fail", 84},
    {READ_FAIL, "Read fail", 84}
};

const int size_error_info = sizeof(error_info) / sizeof(error_t);
