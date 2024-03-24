/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** manage_client
*/

#include "myteams_server.h"
#include <stdarg.h>

void send_message(client_t *client, const char *message)
{
    if (write(client->fd, message, strlen(message)) == -1) {
        printf(RED("Fail to send message to client: ") "%d\n", client->fd);
    }
}

void vsend_message(client_t *client, const char *message, ...)
{
    va_list arg;

    va_start(arg, message);
    vdprintf(client->fd, message, arg);
    va_end(arg);
}

void add_client(server_t *server, client_t *client)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd == 0) {
            memcpy(&server->clients[i], client, sizeof(client_t));
            break;
        }
    }
}

void remove_client(client_t *client)
{
    close(client->fd);
    my_free(client->cwd);
    my_free(client->cmd_buffer);
    memset(client, 0, sizeof(client_t));
}
