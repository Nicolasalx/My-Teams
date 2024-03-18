/*
** EPITECH PROJECT, 2024
** my_filelen
** File description:
** my_filelen
*/

#include "my_error.h"
#include "my_managealloc.h"
#include "my_file.h"
#include <sys/stat.h>

long int my_filelen(const char *filepath)
{
    struct stat st;

    if (stat(filepath, &st) != 0) {
        free_all_alloc();
        print_fatal_error_and_exit(STAT_FAIL);
    }
    return st.st_size;
}
