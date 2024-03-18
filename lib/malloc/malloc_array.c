/*
** EPITECH PROJECT, 2024
** array
** File description:
** malloc_an_array
*/

#include "my_malloc.h"
#include <stdlib.h>

int *malloc_array(int size_array)
{
    return my_malloc(sizeof(int) * size_array);
}
