/*
** EPITECH PROJECT, 2024
** get_max_value
** File description:
** return the index of the max value
*/

int get_max_value(int *array, int size_array)
{
    int max_index = 0;

    for (int i = 0; i < size_array; ++i) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}
