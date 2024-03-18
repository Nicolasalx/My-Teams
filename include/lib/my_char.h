/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_char
*/

#ifndef MY_CHAR_H_
    #define MY_CHAR_H_

    #include <stdbool.h>

bool is_alpha(char c);
bool is_alphanum(char c);
bool is_digit(char c);
bool is_lower(char c);
bool is_upper(char c);
char *to_upper(char *str);
char *to_lower(char *str);

#endif /* !MY_CHAR_H_ */
