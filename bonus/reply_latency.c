/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_latency
*/

#include "myteams_client.h"
#include <sys/time.h>

// ┌, ─, ┐, └, ─, ┘, │, ├

void reply_latency(reply_data_t *reply_data)
{
    struct timeval current_time = {0};
    size_t send_time = 0;
    size_t recv_time = 0;
    size_t reply_time = 0;

    memcpy(&send_time, &reply_data->arg1, sizeof(size_t));
    memcpy(&recv_time, &reply_data->arg1 + sizeof(size_t), sizeof(size_t));
    gettimeofday(&current_time, NULL);
    reply_time = 1000000 * current_time.tv_sec + current_time.tv_usec;
    printf(
        "┌────────┐ \e[96m%.3fms\e[0m ┌────────┐\n"
        "│        │ \e[96m------>\e[0m │        │\n"
        "│ client │         │ server │\n"
        "│        │ \e[95m<------\e[0m │        │\n"
        "└────────┘ \e[95m%.3fms\e[0m └────────┘\n\n"
        "total latency: \e[93m%.3fms\e[0m\n\n",
    (recv_time - send_time) / 1000.0,
    (reply_time - recv_time) / 1000.0,
    (reply_time - send_time) / 1000.0);
}
