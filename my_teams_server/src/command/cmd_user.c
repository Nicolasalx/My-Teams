/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_user
*/

#include "myteams_server.h"

static void send_user_reply(int fd, const char *user_uuid, const char *user_name, int status)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_USER_CMD;
    memcpy(reply_data.arg1.user_uuid, user_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_name, user_name, MAX_NAME_LENGTH);
    memcpy(&reply_data.arg3.user_status, &status, sizeof(int));
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

void cmd_user(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    node_t *current = server->database.user_list;

    if (server->database.user_list == NULL) {
        return;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->uuid, cmd_data->arg1.user_uuid, UUID_LENGTH) == 0) {
            send_user_reply(client->fd,
                GET_DATA(current, db_user_t)->uuid,
                GET_DATA(current, db_user_t)->user_name,
                is_user_connected(server, GET_DATA(current, db_user_t)->uuid));
            return;
        }
        current = current->next;
    } while (current != server->database.user_list);
    send_error_unknown_user(client->fd, cmd_data->arg1.user_uuid);
}
