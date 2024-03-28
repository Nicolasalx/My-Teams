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
    db_user_t *new_user = db_contain_user(&server->database, cmd_data->arg1.user_name);
    uuid_t user_uuid = {0};

    if (new_user == NULL) {
        new_user = my_calloc(sizeof(db_user_t));
        memcpy(new_user->user_name, cmd_data->arg1.user_name, MAX_NAME_LENGTH);
        uuid_generate_random(user_uuid);
        uuid_unparse(user_uuid, new_user->uuid);
        append_node(&server->database.user_list, create_node(new_user));

        server_event_user_created(new_user->uuid, new_user->user_name);
    }
    memcpy(client->user_name, new_user->user_name, MAX_NAME_LENGTH);
    memcpy(client->uuid, new_user->uuid, UUID_LENGTH);
    server_event_user_logged_in(client->uuid);

    // TODO: send reply
}
