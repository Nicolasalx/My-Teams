/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_sum_array
*/

long int sum_array(int *array, int size_array)
{
    long int result = 0;

    for (int i = 0; i < size_array; ++i) {
        result += array[i];
    }
    return result;
}
