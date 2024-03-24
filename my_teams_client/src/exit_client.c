/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** exit_client
*/

#include "myteams_client.h"

void exit_client(int exit_value, const char *message)
{
    if (message != NULL) {
        my_putstr(message);
    }
    delete_client(get_client(NULL));
    my_exit(exit_value);
}
