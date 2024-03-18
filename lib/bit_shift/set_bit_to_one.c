/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** set_bit_to_one
*/

void set_bit_to_one(unsigned char *c, int index_bit)
{
    *c |= 1 << index_bit;
}
