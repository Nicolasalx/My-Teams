/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** create_server
*/

#include "myteams_server.h"

static void create_server_socket(server_t *server)
{
    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server->fd == -1){
        printf(RED("Fail to create the server socket")"\n");
        my_exit(84);
    }
}

static void change_server_option(server_t *server)
{
    int opt = true;

    if (setsockopt(server->fd, SOL_SOCKET,
            SO_REUSEADDR, &opt, sizeof(int)) == -1) {
        printf(RED("Fail to change server socket option")"\n");
        delete_server(server);
        my_exit(84);
    }
}

static void bind_server_address(server_t *server)
{
    server->address.sin_family = AF_INET;
    server->address.sin_port = htons(server->port);
    server->address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(server->fd, (struct sockaddr *) &server->address,
            sizeof(server->address)) == -1) {
        printf(RED("Fail to bind an address to the server")"\n");
        delete_server(server);
        my_exit(84);
    }
}

static void listen_for_connection(server_t *server)
{
    if(listen(server->fd, SOMAXCONN) == -1) {
        printf("Fail to listen for new connection\n");
        delete_server(server);
        my_exit(84);
    }
}

void create_server(server_t *server)
{
    get_server(server);
    create_server_socket(server);
    change_server_option(server);
    bind_server_address(server);
    listen_for_connection(server);
    printf(GREEN("Server successfuly created.")"\n");
}
