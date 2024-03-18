/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_number
*/

#ifndef MY_NUMBER
    #define MY_NUMBER

    #include <stdbool.h>

    #define MAX_INT 2147483647
    #define MIN_INT -2147483648

    #define INT_STR_SIZE 12
    #define DOUBLE_STR_SIZE 25
    #define BOOL_STR_SIZE 6

    #define STR_DOUBLE ((char[DOUBLE_STR_SIZE]) {0})

    #define INT(nb) my_nb_to_str(nb, (char[INT_STR_SIZE]) {0})
    #define DOUBLE(nb, precision) my_double_to_str(nb, precision, STR_DOUBLE)
    #define BOOL(value) my_bool_to_str(value, (char[BOOL_STR_SIZE]) {0})

double my_pow(double nb, int power);
int my_abs(int nb);
int max_value(int value_1, int value_2);
int min_value(int value_1, int value_2);
int my_delta(int value_1, int value_2);

int my_get_nb(const char *str);
int get_min_value(int *array, int size_array);
int get_max_value(int *array, int size_array);
int count_nb_digit(int nb);
int *my_sort(int *array, int size_array);
void my_put_array(const int *array, int size_array,
    const char *separator, const char *last_char);
void my_put_nb(int nb);
long int sum_array(int *array, int size_array);
char *my_nb_to_str(int nb, char *str);
void ini_array(int *array, int value, int size_array);
void my_put_double(double nb, int precision);
void my_put_bool(bool value);
char *my_double_to_str(double nb, int precision, char *str);
char *my_bool_to_str(bool value, char *str);

#endif /* !MY_NUMBER */
