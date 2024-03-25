/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"
#include "command_list.h"

void execute_command(client_t *client, char *command)
{
    cmd_data_t cmd_data = {0};
    /*
    TODO: format the command to send to the server
    */

    if (send(client->fd, &cmd_data, sizeof(cmd_data_t), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}
