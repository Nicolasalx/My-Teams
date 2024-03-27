/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** handle_new_message
*/

#include "myteams_client.h"
#include "reply_list.h"

void handle_new_message(client_t *client)
{
    reply_data_t reply_data = {0};
    ssize_t size = 0;

    if (FD_ISSET(client->fd, &client->set)) {
        size = read(client->fd, &reply_data, sizeof(reply_data_t));
        if (size == 0) {
            exit_client(0, "Server closed the connection.\n");
        } else if (size == -1) {
            exit_client(84, RED("Fail to read message.\n"));
        }
        handle_server_reply(&reply_data);
    }
}
