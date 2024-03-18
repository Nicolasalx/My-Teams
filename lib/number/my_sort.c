/*
** EPITECH PROJECT, 2024
** my_sort
** File description:
** my_sort
*/

#include "my_number.h"
#include "my_bitshift.h"

int *my_sort(int *array, int size_array)
{
    int index_max_value;

    for (int i = (size_array - 1); i > 0; --i) {
        index_max_value = get_max_value(array, i + 1);
        if (i != index_max_value) {
            my_swap(&array[i], &array[index_max_value], sizeof(int));
        }
    }
    return array;
}
