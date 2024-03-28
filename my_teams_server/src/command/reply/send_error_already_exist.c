/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_error_already_exist
*/

#include "myteams_server.h"

void send_error_already_exist(int fd)
{
    reply_data_t reply_data = {0};

    reply_data.type = ERROR_ALREADY_EXIST;
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}
