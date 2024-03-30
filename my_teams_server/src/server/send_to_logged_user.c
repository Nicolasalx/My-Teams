/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_to_logged_user
*/

#include "myteams_server.h"

void send_to_logged_user(client_t *clients, reply_data_t *reply_data)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (clients[i].uuid[0] != '\0') {
            send(clients[i].fd, reply_data, sizeof(reply_data_t), 0);
        }
    }
}
