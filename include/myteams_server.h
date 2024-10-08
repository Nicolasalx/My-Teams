/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** myteams_server
*/

#ifndef MYTEAMS_SERVER_H_
    #define MYTEAMS_SERVER_H_

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
    #include "server_database.h"
    #include "reply_list.h"
    #include "../libs/myteams/logging_server.h"

    #define MAX_CLIENT FD_SETSIZE
    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CLIENT_BUFFER_SIZE 4096
    #define CWD_SIZE 4096

typedef struct {
    context_enum_t type;
    char team_uuid[UUID_LENGTH + 1];
    char channel_uuid[UUID_LENGTH + 1];
    char thread_uuid[UUID_LENGTH + 1];
    node_t *team_ptr;
    node_t *channel_ptr;
    node_t *thread_ptr;
} context_t;

typedef struct {
    int fd;
    char uuid[UUID_LENGTH + 1];
    char user_name[MAX_NAME_LENGTH + 1];
    context_t context;
} client_t;

typedef struct {
    int fd;
    struct sockaddr_in address;
    fd_set read_set;
    fd_set write_set;
    unsigned short port;
    client_t clients[MAX_CLIENT];
    database_t database;
} server_t;

extern void (*const cmd_handler[])(server_t *, client_t *, cmd_data_t *);

void check_arg_validity(int argc, const char **argv, server_t *server);
void create_server(server_t *server);
void init_server_set(server_t *server, int *max_fd);
void monitor_client(server_t *server, int max_fd);
void handle_new_connection(server_t *server);
void lauch_server(server_t *server);
void delete_server(server_t *server);
server_t *get_server(server_t *server);

void add_client(server_t *server, client_t *client);
void remove_client(client_t *client);
void get_client_input(server_t *server, client_t *client);
void execute_client_input(server_t *server, client_t *client,
    cmd_data_t *cmd_data);
bool is_user_connected(server_t *server, const char *user_uuid);
client_t *get_client_by_uuid(server_t *server, const char *uuid);
void send_to_logged_user(client_t *clients, reply_data_t *reply_data);
bool is_valid_context(client_t *client);
void send_reply_to_client(int fd, reply_data_t *reply_data);

void cmd_login(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_logout(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_users(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_user(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_send(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_messages(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_use(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_list(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_info(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_create(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_subscribe(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_subscribed(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_unsubscribe(server_t *server, client_t *client, cmd_data_t *cmd_data);

void cmd_tree(server_t *server, client_t *client, cmd_data_t *cmd_data);
void cmd_latency(server_t *server, client_t *client, cmd_data_t *cmd_data);

void create_new_team(server_t *server, client_t *client, cmd_data_t *cmd_data);
void create_new_channel(server_t *server, client_t *client,
    cmd_data_t *cmd_data);
void create_new_thread(server_t *server, client_t *client,
    cmd_data_t *cmd_data);
void create_new_reply(server_t *server, client_t *client,
    cmd_data_t *cmd_data);

void list_reply(client_t *client);

void send_error_unauthorized(int fd);
void send_error_already_exist(int fd);
void send_error_unknown_channel(int fd, const char *channel_uuid);
void send_error_unknown_team(int fd, const char *team_uuid);
void send_error_unknown_thread(int fd, const char *thread_uuid);
void send_error_unknown_user(int fd, const char *user_uuid);

#endif /* !MYTEAMS_SERVER_H_ */
