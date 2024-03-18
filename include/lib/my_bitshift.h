/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_bitshift
*/

#ifndef MY_BITSHIFT_H_
    #define MY_BITSHIFT_H_

    #include <stddef.h>
    #include <stdbool.h>

bool get_bit_value(unsigned char c, int index_bit);
void set_all_bit_to_zero(unsigned char *c);
void set_bit_to_one(unsigned char *c, int index_bit);
void set_bit_to_zero(unsigned char *c, int index_bit);
void *my_memset(void *data, int value, size_t size);
void my_memcpy(void *dest, const void *src, size_t size);
void my_swap(void *data_1, void *data_2, size_t size);

#endif /* !MY_BITSHIFT_H_ */
