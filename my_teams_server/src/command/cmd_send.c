/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_send
*/

#include "myteams_server.h"

static void send_send_reply(int fd, const char *user_uuid, const char *message_body)
{
    reply_data_t reply_data = {0};

    reply_data.type = PRIVATE_MSG_RECEIVED;
    memcpy(reply_data.arg1.user_uuid, user_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.message_body, message_body, MAX_BODY_LENGTH);
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

void cmd_send(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_private_msg_t *private_msg = my_calloc(sizeof(db_private_msg_t));
    db_user_t *dest_user = db_contain_user_uuid(&server->database, cmd_data->arg1.user_uuid);
    client_t *dest_client = NULL;

    if (dest_user) {
        memcpy(private_msg->sender_uuid, client->uuid, UUID_LENGTH);
        memcpy(private_msg->receiver_uuid, cmd_data->arg1.user_uuid, UUID_LENGTH);
        memcpy(private_msg->msg, cmd_data->arg2.message_body, MAX_BODY_LENGTH);
        private_msg->timestamp = time(NULL);
        append_node(&server->database.private_msg_list, create_node(private_msg));
        server_event_private_message_sended(client->uuid, cmd_data->arg1.user_uuid, cmd_data->arg2.message_body);
        dest_client = get_client_by_uuid(server, private_msg->sender_uuid);
        if (dest_client) {
            send_send_reply(dest_client->fd, private_msg->sender_uuid, private_msg->msg);
        }
    } else {
        send_error_unknown_user(client->fd, cmd_data->arg1.user_uuid);
    }
}
