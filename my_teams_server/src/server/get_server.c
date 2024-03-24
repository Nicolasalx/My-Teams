/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** get_server
*/

#include "myteams_server.h"

server_t *get_server(server_t *server)
{
    static server_t *server_ptr = NULL;

    if (server != NULL) {
        server_ptr = server;
    }
    return server_ptr;
}
