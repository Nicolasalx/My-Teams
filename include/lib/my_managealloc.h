/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_managealloc
*/

#ifndef MY_MANAGEALLOC_H_
    #define MY_MANAGEALLOC_H_

    #include <stddef.h>

void *register_alloc(void *data);
void force_register_alloc(void **data, size_t size);
void free_all_alloc(void);

#endif /* !MY_MANAGEALLOC_H_ */
