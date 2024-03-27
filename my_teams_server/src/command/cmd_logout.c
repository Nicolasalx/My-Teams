/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_logout
*/

#include "myteams_server.h"

void cmd_logout(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    server_event_user_logged_out(client->uuid);
    
    // TODO: send reply
    
    remove_client(client);
}
