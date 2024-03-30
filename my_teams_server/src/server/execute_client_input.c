/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_client_input
*/

#include "myteams_server.h"
#include "command_list.h"

void execute_client_input(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    if (cmd_data->type < NUMBER_CMD) {
        printf("Received: %s\n", command_list[cmd_data->type].name);
    }
    for (size_t i = 0; i < NUMBER_CMD; ++i) {
        if (cmd_data->type == i && cmd_handler[i]) {
            cmd_handler[i](server, client, cmd_data);
            break;
        }
    }
}
