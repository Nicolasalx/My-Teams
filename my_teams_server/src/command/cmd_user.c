/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_user
*/

#include "myteams_server.h"

void cmd_user(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    node_t *current = server->database.user_list;

    if (server->database.user_list == NULL) {
        return;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->uuid, cmd_data->arg1.user_uuid, UUID_LENGTH) == 0) {
            // TODO: send reply: REPLY_USER
            return;
        }
        current = current->next;
    } while (current != server->database.user_list);
    // TODO: manage when user not found
}
