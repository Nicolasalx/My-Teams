/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** ini_array
*/

void ini_array(int *array, int value, int size_array)
{
    for (int i = 0; i < size_array; ++i) {
        array[i] = value;
    }
}
