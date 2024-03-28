/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_users
*/

#include "myteams_server.h"

static void send_users_reply(int fd, const char *user_uuid, const char *user_name, int status)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_USERS_CMD;
    memcpy(reply_data.arg1.user_uuid, user_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_name, user_name, MAX_NAME_LENGTH);
    memcpy(&reply_data.arg3.user_status, &status, sizeof(int));
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

void cmd_users(server_t *server, client_t *client, cmd_data_t *)
{
    node_t *current = server->database.user_list;

    if (server->database.user_list == NULL) {
        return;
    }
    do {
        send_users_reply(client->fd,
            GET_DATA(current, db_user_t)->uuid,
            GET_DATA(current, db_user_t)->user_name,
            is_user_connected(server, GET_DATA(current, db_user_t)->uuid));
        current = current->next;
    } while (current != server->database.user_list);
}
