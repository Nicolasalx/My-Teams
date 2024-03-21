/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** myteams_server
*/

#ifndef MYTEAMS_SERVER_H_
    #define MYTEAMS_SERVER_H_

    #include "my_importall.h"

    #define MAX_CLIENT FD_SETSIZE
    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096

typedef struct {
    //int fd;
    //struct sockaddr_in address;
    //fd_set set;
    //char *cwd;
    unsigned short port;
    //client_t clients[MAX_CLIENT];
} server_t;

#endif /* !MYTEAMS_SERVER_H_ */
