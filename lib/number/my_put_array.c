/*
** EPITECH PROJECT, 2024
** my_putarray
** File description:
** my_putarray
*/

#include "my_number.h"
#include "my_string.h"

void my_put_array(const int *array, int size_array,
    const char *separator, const char *last_char)
{
    for (int i = 0; i < size_array; ++i) {
        my_put_nb(array[i]);
        if (i + 1 < size_array) {
            my_putstr(separator);
        } else {
            my_putstr(last_char);
        }
    }
}
