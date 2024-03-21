/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** myteams_client
*/

#ifndef MYTEAMS_CLIENT_H_
    #define MYTEAMS_CLIENT_H_

    #include "my_importall.h"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <string.h>
    #include <stdlib.h>

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

typedef struct {
    struct sockaddr_in address;
    unsigned short port;
} client_t;

void check_arg_validity(int argc, const char **argv, client_t *client);

#endif /* !MYTEAMS_CLIENT_H_ */
