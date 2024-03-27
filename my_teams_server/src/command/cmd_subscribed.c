/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_subscribed
*/

#include "myteams_server.h"

void cmd_subscribed(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    if (cmd_data->arg4.nb_arg == 0) {
        // TODO send REPLY_SUBSCRIBED_TEAMS_CMD
    } else {
        // TODO send REPLY_SUBSCRIBED_USER_CMD
        // TODO send error ERROR_UNKNOWN_TEAM
    }
}
