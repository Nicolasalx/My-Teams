/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_create
*/

#include "myteams_server.h"
#include <uuid/uuid.h>

void cmd_create(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    switch (client->context.type) {
    case NO_CONTEXT:
        create_new_team(server, client, cmd_data);
        break;
    case IN_TEAM:
        create_new_channel(server, client, cmd_data);
        break;
    case IN_CHANNEL:
        create_new_thread(server, client, cmd_data);
        break;
    case IN_THREAD:
        create_new_reply(server, client, cmd_data);
        break;
    }
}
