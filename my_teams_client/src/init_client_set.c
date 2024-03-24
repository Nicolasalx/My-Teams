/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** init_client_set
*/

#include "myteams_client.h"

void init_client_set(client_t *client, int *max_fd)
{
    FD_ZERO(&client->set);
    FD_SET(STDIN_FILENO, &client->set);
    FD_SET(client->fd, &client->set);

    *max_fd = client->fd;
}

void monitor_input(client_t *client, int max_fd)
{
    if (select(max_fd + 1, &client->set, NULL, NULL, NULL) == -1) {
        exit_client(84, RED("Select fail.\n"));
    }
}
