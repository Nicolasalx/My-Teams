/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_latency
*/

#include "myteams_server.h"
#include <sys/time.h>

void cmd_latency(server_t *, client_t *client, cmd_data_t *cmd_data)
{
    reply_data_t reply_data = {0};
    struct timeval current_time = {0};
    size_t server_time = 0;

    reply_data.type = REPLY_LATENCY;
    memcpy(&reply_data.arg1, &cmd_data->arg1, sizeof(size_t));
    gettimeofday(&current_time, NULL);
    server_time = 1000000 * current_time.tv_sec + current_time.tv_usec;
    memcpy(&reply_data.arg1 + sizeof(size_t), &server_time, sizeof(size_t));
    send(client->fd, &reply_data, sizeof(reply_data_t), 0);
}
