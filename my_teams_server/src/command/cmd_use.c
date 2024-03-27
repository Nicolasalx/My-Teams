/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_use
*/

#include "myteams_server.h"

void cmd_use(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    memcpy(client->context.team_uuid, cmd_data->arg1.team_uuid, UUID_LENGTH);
    memcpy(client->context.channel_uuid, cmd_data->arg2.channel_uuid, UUID_LENGTH);
    memcpy(client->context.thread_uuid, cmd_data->arg3.thread_uuid, UUID_LENGTH);
    client->context.type = cmd_data->arg4.nb_arg;
}
