/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_message
*/

#include "myteams_server.h"

void cmd_messages(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    node_t *current = server->database.private_msg_list;

    if (server->database.private_msg_list == NULL) {
        return;
    }
    do {
        if (memcmp(GET_DATA(current, db_private_msg_t)->receiver_uuid, client->uuid, UUID_LENGTH) == 0
        || memcmp(GET_DATA(current, db_private_msg_t)->sender_uuid, client->uuid, UUID_LENGTH) == 0) {
            // TODO: send reply: REPLY_MESSAGES_CMD
        }
        current = current->next;
    } while (current != server->database.private_msg_list);
}
