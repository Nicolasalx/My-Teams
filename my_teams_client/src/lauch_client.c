/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** lauch_client
*/

#include "myteams_client.h"
#include <signal.h>

void close_client(int)
{
    exit_client(0, NULL);
}

void lauch_client(client_t *client)
{
    int max_fd = 0;

    signal(SIGINT, close_client);
    while (true) {
        init_client_set(client, &max_fd);
        monitor_input(client, max_fd);
        handle_new_input(client);
        handle_new_message(client);
    }
}
