/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** is_user_connexted
*/

#include "myteams_server.h"

bool is_user_connected(server_t *server, const char *user_uuid)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd > 0 && memcmp(server->clients[i].uuid, user_uuid, UUID_LENGTH) == 0) {
            return true;
        }
    }
    return false;
}
