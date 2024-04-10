/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_reply_to_client
*/

#include "myteams_server.h"

void send_reply_to_client(int fd, reply_data_t *reply_data)
{
    if (FD_ISSET(fd, &get_server(NULL)->write_set)) {
        if (send(fd, reply_data, sizeof(reply_data_t), 0) == -1) {
            my_putstr(RED("Fail to send reply to client.\n"));
        }
    }
}
