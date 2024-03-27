/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_create
*/

#include "myteams_server.h"

void cmd_create(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    // TODO: send request & error
    switch (client->context.type) {
    case NO_CONTEXT:
        /* code */
        break;
    case IN_TEAM:
        /* code */
        break;
    case IN_CHANNEL:
        /* code */
        break;
    case IN_THREAD:
        /* code */
        break;
    }
}
