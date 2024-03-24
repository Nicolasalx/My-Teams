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

    #define MAX_CLIENT FD_SETSIZE
    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CLIENT_BUFFER_SIZE 4096
    #define CWD_SIZE 4096

typedef struct {
    int fd;
    bool entered_loggin;
    bool logged_in;
    bool has_valid_username;
    char *cwd;
    char *cmd_buffer;
} client_t;

typedef struct {
    int fd;
    struct sockaddr_in address;
    fd_set set;
    char *cwd;
    unsigned short port;
    client_t clients[MAX_CLIENT];
} server_t;

typedef struct {
    char *str;
    bool need_logged_in;
    void (*handler)(client_t *, int, char **);
    char *help;
} command_t;

extern const command_t command_list[];

typedef enum {
    C150_OPEN_DATA_CONNECTION,
    C200_COMMAND_OK,
    C214_HELP_MESSAGE,
    C220_SERVICE_READY,
    C221_LOGOUT,
    C226_CLOSING_DATA_CONNECTION,
    C227_ENTERING_PASSIVE_MODE,
    C230_USER_LOGGED_IN_PROCEED,
    C250_REQUEST_FILE_ACTION_OK,
    C257_PATH_CREATED,
    C331_USERNAME_OK,
    C332_NEED_ACCOUNT,
    C425_CANT_OPEN_DATA_CONNECTION,
    C426_TRANSFER_ABORTED,
    C451_LOCAL_ERROR_IN_PROCESSING,
    C500_SYNTAX_ERROR,
    C501_ARGUMENT_ERROR,
    C503_BAD_SEQUENCE,
    C530_NOT_LOGGED_IN,
    C550_FILE_UNAVAILABLE,
    C553_FILE_NAME_NOT_ALLOWED
} reply_e;

extern const char *reply_code[];

void check_arg_validity(int argc, const char **argv, server_t *server);
void create_server(server_t *server);
void init_server_set(server_t *server, int *max_fd);
void monitor_client(server_t *server, int max_fd);
void handle_new_connection(server_t *server);
void lauch_server(server_t *server);
void delete_server(server_t *server);
const server_t *get_server(const server_t *server);

void send_message(client_t *client, const char *message);
void vsend_message(client_t *client, const char *message, ...);
void add_client(server_t *server, client_t *client);
void remove_client(client_t *client);
void init_client_cwd(client_t *client);

bool require_logged_in(char *command);

#endif /* !MYTEAMS_SERVER_H_ */
