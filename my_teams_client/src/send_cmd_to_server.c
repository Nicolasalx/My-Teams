/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_cmd_to_server
*/

#include "myteams_client.h"

void send_cmd_to_server(client_t *client, cmd_data_t *cmd_data)
{
    if (FD_ISSET(client->fd, &client->write_set)) {
        if (send(client->fd, cmd_data, sizeof(cmd_data_t), 0) == -1) {
            my_putstr(RED("Fail to send message to server.\n"));
        }
    }
}
