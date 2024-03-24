/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"

void execute_command(client_t *client, char *command)
{
    /*
    TODO: format the command to send to the server
    */
    if (send(client->fd, command, strlen(command), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}
