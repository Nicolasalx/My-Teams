/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_error_unknown_channel
*/

#include "myteams_server.h"

void send_error_unknown_channel(int fd, const char *channel_uuid)
{
    reply_data_t reply_data = {0};

    reply_data.type = ERROR_UNKNOWN_CHANNEL;
    memcpy(reply_data.arg1.channel_uuid, channel_uuid, UUID_LENGTH);
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}
