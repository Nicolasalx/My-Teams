/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_malloc
*/

#ifndef MY_MALLOC
    #define MY_MALLOC

    #include <stddef.h>
    #include <stdbool.h>
    #include "internal/my_warning.h"
    #include <string.h>

void *my_malloc(size_t size);
void *my_calloc(size_t size);
void my_free(void *data);
char **malloc_board(int nb_line, int size_line);
void free_board(void **board);
char *malloc_str(int size_str);
char **my_str_to_board(const char *str, int nb_line, const int *size_line);
int *malloc_array(int size_array);
int *count_size_word(const char *str, const char *delimiter, int nb_word);
char **my_str_to_word(const char *str, const char *delimiter,
    int nb_word, const int *size_word);
char **malloc_adv_board(int nb_line, const int *size_line);
char *my_adv_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
char **my_boarddup(char **board);
char *my_adv_strcpy(char *dest, const char *src);
int *count_size_word_wm(const char *str, bool (*method)(char), int nb_word);
char **my_str_to_word_wm(const char *str, bool (*method)(char),
    int nb_word, const int *size_word);
void **malloc_gn_adv_board(int nb_line, int *size_line, size_t size);
void **malloc_gn_board(int nb_line, int size_line, size_t size);

#endif /* !MY_MALLOC */
