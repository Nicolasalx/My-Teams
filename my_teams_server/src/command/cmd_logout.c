/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_logout
*/

#include "myteams_server.h"

static void send_logout_reply(int fd, const char *user_uuid, const char *user_name)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_LOGGED_OUT;
    memcpy(reply_data.arg1.user_uuid, user_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_name, user_name, MAX_NAME_LENGTH);
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

void cmd_logout(server_t *, client_t *client, cmd_data_t *)
{
    SERVER_EVENT_USER_LOGGED_OUT(client->uuid);
    send_logout_reply(client->fd, client->uuid, client->user_name);
    remove_client(client);
}
