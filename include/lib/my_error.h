/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_error
*/

#ifndef MY_ERROR
    #define MY_ERROR

    #include "my_def.h"
    #include <string.h>

typedef enum error_code_enum {
    NO_ERROR,
    MALLOC_FAIL,
    STAT_FAIL,
    READ_FAIL
} error_code_enum_t;

typedef struct error_t {
    int code;
    const char *message;
    int return_value;
} error_t;

extern const error_t error_info[];
extern const int size_error_info;

void my_puterror(const char *str);
void print_fatal_error_and_exit(int error);
void my_exit(int exit_value);

#endif /* !MY_ERROR */
