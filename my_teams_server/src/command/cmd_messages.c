/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_message
*/

#include "myteams_server.h"

static void send_messages_reply(int fd, const char *sender_uuid,
    time_t message_timestamp, const char *message_body)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_MESSAGES_CMD;
    memcpy(reply_data.arg1.sender_uuid, sender_uuid, UUID_LENGTH);
    memcpy(&reply_data.arg2.message_timestamp, &message_timestamp, sizeof(time_t));
    memcpy(reply_data.arg3.message_body, message_body, MAX_BODY_LENGTH);
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

void cmd_messages(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    node_t *current = server->database.private_msg_list;

    if (!db_contain_user_uuid(&server->database, cmd_data->arg1.user_uuid)) {
        send_error_unknown_user(client->fd, cmd_data->arg1.user_uuid);
        return;
    }
    if (server->database.private_msg_list == NULL) {
        return;
    }
    do {
        if (memcmp(GET_DATA(current, db_private_msg_t)->receiver_uuid, client->uuid, UUID_LENGTH) == 0
        || memcmp(GET_DATA(current, db_private_msg_t)->sender_uuid, client->uuid, UUID_LENGTH) == 0) {
            send_messages_reply(client->fd,
                GET_DATA(current, db_private_msg_t)->sender_uuid,
                GET_DATA(current, db_private_msg_t)->timestamp,
                GET_DATA(current, db_private_msg_t)->msg);
        }
        current = current->next;
    } while (current != server->database.private_msg_list);
}
