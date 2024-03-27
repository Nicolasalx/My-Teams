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
    #define CMD_BUFFER_SIZE 4096

typedef struct {
    int fd;
    fd_set set;
    unsigned short port;
    struct sockaddr_in server_address;
    char *cmd_buffer;
} client_t;

extern void (*const reply_handler[])(reply_data_t *);

void check_arg_validity(int argc, const char **argv, client_t *client);
void create_client(client_t *client);
client_t *get_client(client_t *client);
void init_client_set(client_t *client, int *max_fd);
void monitor_input(client_t *client, int max_fd);

void execute_command(client_t *client, char *command);
void handle_new_input(client_t *client);
void handle_new_message(client_t *client);
void handle_server_reply(reply_data_t *reply_data);

void lauch_client(client_t *client);
void delete_client(client_t *client);
void exit_client(int exit_value, const char *message);

#endif /* !MYTEAMS_CLIENT_H_ */
