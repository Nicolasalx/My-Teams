/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_send
*/

#include "myteams_server.h"

void cmd_send(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_private_msg_t *private_msg = my_calloc(sizeof(db_private_msg_t));

    memcpy(private_msg->sender_uuid, client->uuid, UUID_LENGTH);
    memcpy(private_msg->receiver_uuid, cmd_data->arg1.user_uuid, UUID_LENGTH);
    memcpy(private_msg->msg, cmd_data->arg2.message_body, MAX_BODY_LENGTH);
    append_node(&server->database.private_msg_list, create_node(private_msg));
    server_event_private_message_sended(client->uuid, cmd_data->arg1.user_uuid, cmd_data->arg2.message_body);

    // TODO: check if receiver exist
    // TODO: send reply PRIVATE_MSG_RECEIVED
}
