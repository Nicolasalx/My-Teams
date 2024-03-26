/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_login
*/

#include "myteams_server.h"
#include <uuid/uuid.h>

void cmd_login(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    // manage database
    uuid_t user_uuid;

    memcpy(client->user_name, cmd_data->arg1.user_name, MAX_NAME_LENGTH);
    uuid_generate_random(user_uuid);
    uuid_unparse(user_uuid, client->uuid);
    server_event_user_logged_in(client->uuid);
}
