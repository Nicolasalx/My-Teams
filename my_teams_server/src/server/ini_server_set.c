/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** ini_server_set
*/

#include "myteams_server.h"

void init_server_set(server_t *server, int *max_fd)
{
    FD_ZERO(&server->read_set);
    FD_SET(server->fd, &server->read_set);
    FD_ZERO(&server->write_set);
    FD_SET(server->fd, &server->write_set);
    *max_fd = server->fd;
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0) {
            FD_SET(server->clients[i].fd, &server->read_set);
            FD_SET(server->clients[i].fd, &server->write_set);
        }
        if (server->clients[i].fd > *max_fd) {
            *max_fd = server->clients[i].fd;
        }
    }
}
