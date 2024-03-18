/*
** EPITECH PROJECT, 2024
** get_min_in_range
** File description:
** return the index of the min value
*/

int get_min_value(int *array, int size_array)
{
    int min_index = 0;

    for (int i = 0; i < size_array; ++i) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}
