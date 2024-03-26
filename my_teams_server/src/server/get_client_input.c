/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** get_client_input
*/

#include "myteams_server.h"

void get_client_input(server_t *server, client_t *client)
{
    cmd_data_t cmd_data = {0};
    ssize_t nb_byte = read(client->fd, &cmd_data, sizeof(cmd_data_t));

    if (nb_byte == 0) {
        printf(YELLOW("A client as left")"\n");
        remove_client(client);
        return;
    }
    execute_client_input(server, client, &cmd_data);
}
