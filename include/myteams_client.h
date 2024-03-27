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
    #include "command_list.h"

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

extern context_e context;

void check_arg_validity(int argc, const char **argv, client_t *client);
void create_client(client_t *client);
client_t *get_client(client_t *client);
void init_client_set(client_t *client, int *max_fd);
void monitor_input(client_t *client, int max_fd);

void execute_command(client_t *client, char *command);
void handle_new_input(client_t *client);
void handle_new_message(client_t *client);

command_type_e init_user(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_help(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_login(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_logout(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_users(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_send(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_messages(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_subscribe(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_subscribed(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_unsubscribe(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_use(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_create(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_list(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);
command_type_e init_info(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command);

void lauch_client(client_t *client);
void delete_client(client_t *client);
void exit_client(int exit_value, const char *message);

#endif /* !MYTEAMS_CLIENT_H_ */
