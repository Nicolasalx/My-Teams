/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "myteams_client.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void check_nb_arg(int argc)
{
    if (argc != 3) {
        printf(RED("Too much or missing argument\n")
        "\nUSAGE: ./myteams_cli ip port\n"
        "\tip is the server ip address on which the server socket listens.\n"
        "\tport is the port number on which the server socket listens.\n");
        my_exit(84);
    }
}

void check_arg_validity(int argc, const char **argv, client_t *client)
{
    check_nb_arg(argc);
    if (strcmp(argv[1], "localhost") == 0) {
        inet_aton(argv[1], &client->server_address.sin_addr);
    } else {
        if (inet_aton(argv[1], &client->server_address.sin_addr) == 0) {
            printf("Invalid Ip: %s\n", argv[1]);
            my_exit(84);
        }
    }
    if (!my_str_only_cont(argv[2], "0123456789")
    || strlen(argv[2]) > 5 || atoi(argv[2]) > MAX_PORT_NB) {
        printf("Invalid port: %s\n", argv[2]);
        my_exit(84);
    }
    client->port = atoi(argv[2]);
}
