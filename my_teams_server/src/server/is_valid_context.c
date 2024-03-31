/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** is_valid_context
*/

#include "myteams_server.h"

bool is_valid_context(client_t *client)
{
    if (client->context.type >= IN_TEAM && !client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return false;
    }
    if (client->context.type >= IN_CHANNEL && !client->context.channel_ptr) {
        send_error_unknown_channel(client->fd, client->context.channel_uuid);
        return false;
    }
    if (client->context.type >= IN_THREAD && !client->context.thread_ptr) {
        send_error_unknown_thread(client->fd, client->context.thread_uuid);
        return false;
    }
    return true;
}
