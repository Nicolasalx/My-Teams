/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_string
*/

#ifndef MY_STRING
    #define MY_STRING

    #include <stdbool.h>
    #include <stddef.h>
    #include "my_number.h"
    #include <string.h>

    #define CHAR(character) ((char[2]) {(char) character, '\0'})

void my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
bool is_in_str(char c, const char *str);
bool my_str_only_cont(const char *str, const char *characters);
int count_occur(const char *str, char c);
bool my_str_cont_atleast(const char *str, const char *characters);
int count_nb_word(const char *str, const char *delimiter);
char *my_revstr(char *str);
void my_putboard(char **board, const char *separator, const char *last_char);
void my_putchar(char c);
int my_strncmp(const char *str1, const char *str2, int n);
void shift_str_to_left(char *str, int nb_shift);
int my_boardlen(char **board);
int count_nb_word_wm(const char *str, bool (*method)(char));
void my_put_fd(int fd, char *str);
void my_put_fd_fm(int fd, int nb_str, ...);
char *my_strncat(char *dest, const char *src, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
char *build_str(char *dest, int nb_str, ...);

#endif /* !MY_STRING */
