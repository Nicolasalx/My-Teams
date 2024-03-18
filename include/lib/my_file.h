/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_file
*/

#ifndef MY_FILE
    #define MY_FILE

    #include <stdbool.h>
    #include <sys/stat.h>
    #include <string.h>

int open_file(const char *filepath);
long int my_filelen(const char *filepath);
char *my_file_to_str(int file, long int size_file);
int count_nb_line(const char *str);
int *count_lines_size(const char *str, int nb_line);
bool is_a_dir(const char *path);

#endif /* !MY_FILE */
