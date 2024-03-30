/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** delete_server
*/

#include "myteams_server.h"
#include <dlfcn.h>

void delete_server(server_t *server)
{
    fflush(NULL);
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        remove_client(&server->clients[i]);
    }
    close(server->fd);
    dlclose(server->handle);
}
