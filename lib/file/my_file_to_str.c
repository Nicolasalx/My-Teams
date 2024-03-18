/*
** EPITECH PROJECT, 2024
** my_file_to_str
** File description:
** my_file_to_str
*/

#include "my_error.h"
#include "my_malloc.h"
#include "my_managealloc.h"
#include "my_file.h"
#include <stdlib.h>
#include <unistd.h>

char *my_file_to_str(int file, long int size_file)
{
    char *buff = my_malloc(sizeof(char) * (size_file + 1));

    if (read(file, buff, size_file) != size_file) {
        free_all_alloc();
        print_fatal_error_and_exit(READ_FAIL);
    }
    buff[size_file] = '\0';
    return buff;
}
