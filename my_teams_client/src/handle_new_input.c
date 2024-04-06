/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** handle_new_input
*/

#include "myteams_client.h"

static void buffering_input(client_t *client, char *command, ssize_t nb_byte)
{
    char *start_cmd = command;
    char *end_cmd = strchr(command, '\n');

    while (end_cmd != NULL) {
        strncat(client->cmd_buffer, command, (end_cmd + 1) - start_cmd);
        execute_command(client, client->cmd_buffer);
        if (client->cmd_buffer == NULL) {
            return;
        }
        memset(client->cmd_buffer, 0, CMD_BUFFER_SIZE);
        memmove(start_cmd, end_cmd + 1, strlen(end_cmd + 1) + 1);
        end_cmd = strchr(command, '\n');
    }
    strncat(client->cmd_buffer, start_cmd, nb_byte);
}

static void handle_ctrl_d(client_t *client, ssize_t nb_byte)
{
    cmd_data_t cmd_data = {0};

    if (nb_byte == 0) {
        if (isLogin == LOGGED_IN) {
            cmd_data.type = LOGOUT;
            send_cmd_to_server(client, &cmd_data);
        } else {
            exit_client(0, NULL);
        }
    }
}

void handle_new_input(client_t *client)
{
    char command[BUFFER_SIZE + 1] = {0};
    ssize_t nb_byte = 0;

    if (FD_ISSET(STDIN_FILENO, &client->read_set)) {
        nb_byte = read(STDIN_FILENO, command, BUFFER_SIZE);
        handle_ctrl_d(client, nb_byte);
        buffering_input(client, command, nb_byte);
    }
}
