/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** create_client
*/

#include "myteams_client.h"

void create_client(client_t *client)
{
    get_client(client);
    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd == -1) {
        exit_client(84, RED("Fail to create the client socket\n"));
    }

    client->server_address.sin_family = AF_INET;
    client->server_address.sin_port = htons(client->port);

    if (connect(client->fd, (struct sockaddr *) &client->server_address, sizeof(client->server_address)) != 0) {
        exit_client(84, RED("Connection to the server failed.\n"));
    }
    client->cmd_buffer = my_calloc(sizeof(char) * (CMD_BUFFER_SIZE + 1));
}
