/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_cmd_to_server
*/

#include "myteams_client.h"

void try_send_prev_cmd(client_t *client)
{
    while (client->cmd_to_send) {
        if (FD_ISSET(client->fd, &client->write_set)) {
            if (send(client->fd, GET_DATA(client->cmd_to_send, cmd_data_t), sizeof(cmd_data_t), 0) == -1) {
                my_putstr(RED("Fail to send message to server.\n"));
            }
            delete_node(&client->cmd_to_send, client->cmd_to_send);
        } else {
            return;
        }
    }
}

void send_cmd_to_server(client_t *client, cmd_data_t *cmd_data)
{
    try_send_prev_cmd(client);
    if (client->cmd_to_send) {
        append_node(&client->cmd_to_send, create_node(cmd_data));
        return;
    }
    if (FD_ISSET(client->fd, &client->write_set)) {
        if (send(client->fd, cmd_data, sizeof(cmd_data_t), 0) == -1) {
            my_putstr(RED("Fail to send message to server.\n"));
        }
        return;
    }
    append_node(&client->cmd_to_send, create_node(cmd_data));
}
