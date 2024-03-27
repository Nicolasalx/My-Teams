/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** manage_client
*/

#include "myteams_server.h"
#include <stdarg.h>

void add_client(server_t *server, client_t *client)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd == 0) {
            memcpy(&server->clients[i], client, sizeof(client_t));
            break;
        }
    }
}

void remove_client(client_t *client)
{
    close(client->fd);
    memset(client, 0, sizeof(client_t));
}
