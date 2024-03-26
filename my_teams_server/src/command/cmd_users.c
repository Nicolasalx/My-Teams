/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_users
*/

#include "myteams_server.h"

void cmd_users(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    node_t *current = server->database.user_list;

    if (server->database.user_list == NULL) {
        return;
    }
    do {
        // TODO: send reply: REPLY_USERS
        current = current->next;
    } while (current != server->database.user_list);
}
