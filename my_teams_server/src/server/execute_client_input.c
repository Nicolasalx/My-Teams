/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_client_input
*/

#include "myteams_server.h"
#include "command_list.h"

void execute_client_input(client_t *client, cmd_data_t *cmd_data)
{
    printf("Received: %s\n", command_list[cmd_data->type].name);
}
