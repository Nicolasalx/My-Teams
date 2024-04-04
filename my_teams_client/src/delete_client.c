/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** delete_client
*/

#include "myteams_client.h"
#include <dlfcn.h>

void delete_client(client_t *client)
{
    if (client == NULL) {
        return;
    }
    if (client->fd > 0) {
        close(client->fd);
    }
}
