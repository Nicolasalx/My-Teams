/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_def
*/

#ifndef MY_DEF_H_
    #define MY_DEF_H_

    #define BOLD(str) "\e[1m" str "\e[0m"
    #define UNDERLINE(str) "\e[4m" str "\e[0m"

    #define RED(str) "\e[91m" str "\e[0m"
    #define GREEN(str) "\e[92m" str "\e[0m"
    #define YELLOW(str) "\e[93m" str "\e[0m"
    #define BLUE(str) "\e[94m" str "\e[0m"
    #define MAGENTA(str) "\e[95m" str "\e[0m"
    #define CYAN(str) "\e[96m" str "\e[0m"

    #define BOLD_RED(str) "\e[1m\e[91m" str "\e[0m"
    #define BOLD_GREEN(str) "\e[1m\e[92m" str "\e[0m"
    #define BOLD_YELLOW(str) "\e[1m\e[93m" str "\e[0m"
    #define BOLD_BLUE(str) "\e[1m\e[94m" str "\e[0m"
    #define BOLD_MAGENTA(str) "\e[1m\e[95m" str "\e[0m"
    #define BOLD_CYAN(str) "\e[1m\e[96m" str "\e[0m"

    #define UNUSED(var) (void) (var)

    #define ADD_QUOTE(value) #value
    #define STR(value) ADD_QUOTE(value)

    #define NB_ELEM(data) (sizeof(data) / sizeof(*data))

    #define BOARDIFY(type, ...) ((type *[]) {__VA_ARGS__, NULL})

    #define CAST_BACK(data, type) ((type *) data)

    #define SET_NULL(var) var = NULL

#endif /* !MY_DEF_H_ */
