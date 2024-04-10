/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "myteams_server.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void check_arg_validity(int argc, const char **argv, server_t *server)
{
    if (argc != 2) {
        printf(RED("Too much or missing argument\n")
        "\nUSAGE: ./myteams_server port\n"
        "\tport is the port number on which the server socket listens.\n");
        my_exit(84);
    }
    if (!my_str_only_cont(argv[1], "0123456789")
    || strlen(argv[1]) > 5 || atoi(argv[1]) > MAX_PORT_NB) {
        printf("Invalid port: "RED("%s")"\n", argv[1]);
        my_exit(84);
    }
    server->port = atoi(argv[1]);
}
