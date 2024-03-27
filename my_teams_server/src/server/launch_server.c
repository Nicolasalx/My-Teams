/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** lauch_server
*/

#include "myteams_server.h"
#include <signal.h>

void handle_active_client(server_t *server)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (FD_ISSET(server->clients[i].fd, &server->set)) {
            get_client_input(&server->clients[i]);
        }
    }
}

void close_server(int)
{
    delete_server(get_server(NULL));
    my_exit(0);
}

void lauch_server(server_t *server)
{
    int max_fd = server->fd;

    signal(SIGINT, close_server);
    while (true) {
        init_server_set(server, &max_fd);
        monitor_client(server, max_fd);
        handle_new_connection(server);
        handle_active_client(server);
    }
}
