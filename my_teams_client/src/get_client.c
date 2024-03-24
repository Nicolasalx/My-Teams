/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** get_client
*/

#include "myteams_client.h"

client_t *get_client(client_t *client)
{
    static client_t *client_save = NULL;

    if (client) {
        client_save = client;
    }
    return client_save;
}
