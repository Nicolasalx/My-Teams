/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** lauch_server
*/

#include "myteams_server.h"
#include <signal.h>

static void get_client_input(client_t *client)
{
    char command[BUFFER_SIZE + 1] = {0};
    ssize_t nb_byte = read(client->fd, command, BUFFER_SIZE);

    if (nb_byte == 0) {
        printf(YELLOW("A client as left")"\n");
        remove_client(client);
        return;
    }
    printf(MAGENTA("New client message(%zu): ") "\"%s\"\n", nb_byte, command);
    write(client->fd, "Hello\r\n", 7);
}

void handle_active_client(server_t *server)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (FD_ISSET(server->clients[i].fd, &server->set)) {
            get_client_input(&server->clients[i]);
        }
    }
}

void lauch_server(server_t *server)
{
    int max_fd = server->fd;

    while (true) {
        init_server_set(server, &max_fd);
        monitor_client(server, max_fd);
        handle_new_connection(server);
        handle_active_client(server);
    }
}
