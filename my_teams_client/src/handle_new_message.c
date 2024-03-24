/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** handle_new_message
*/

#include "myteams_client.h"

void handle_new_message(client_t *client)
{
    char buff[BUFFER_SIZE + 1] = {0}; // ! replace by macro
    ssize_t size = 0;

    if (FD_ISSET(client->fd, &client->set)) {
        size = read(client->fd, buff, BUFFER_SIZE); // ! replace by macro
        if (size == 0) {
            exit_client(0, "Server closed the connection.\n");
        } else if (size == -1) {
            exit_client(84, RED("Fail to read message.\n"));
        }
        printf("Server: %s", buff);
    }
}
