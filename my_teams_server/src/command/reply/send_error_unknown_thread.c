/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_error_unknown_thread
*/

#include "myteams_server.h"

void send_error_unknown_thread(int fd, const char *thread_uuid)
{
    reply_data_t reply_data = {0};

    reply_data.type = ERROR_UNKNOWN_THREAD;
    memcpy(reply_data.arg1.thread_uuid, thread_uuid, UUID_LENGTH);
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}
