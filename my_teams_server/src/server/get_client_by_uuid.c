/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** get_client_by_uuid
*/

#include "myteams_server.h"

client_t *get_client_by_uuid(server_t *server, const char *uuid)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd > 0 && memcmp(server->clients[i].uuid, uuid, UUID_LENGTH) == 0) {
            return &server->clients[i];
        }
    }
    return NULL;
}
