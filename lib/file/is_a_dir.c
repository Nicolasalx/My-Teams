/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** is_a_dir
*/

#include "my_error.h"
#include "my_managealloc.h"
#include "my_file.h"
#include <sys/stat.h>
#include <stdbool.h>
#include <stdio.h>

bool is_a_dir(const char *path)
{
    struct stat st;

    if (stat(path, &st) != 0) {
        free_all_alloc();
        printf("%s\"%s\"\n", RED("Invalid file path: "), path);
        my_exit(84);
    }
    return S_ISDIR(st.st_mode);
}
