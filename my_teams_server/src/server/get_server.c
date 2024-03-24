/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** get_server
*/

#include "myteams_server.h"

const server_t *get_server(const server_t *server)
{
    static const server_t *server_ptr = NULL;

    if (server != NULL) {
        server_ptr = server;
    }
    return server_ptr;
}
