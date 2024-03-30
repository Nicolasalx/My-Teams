/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** create_new_team
*/

#include "myteams_server.h"
#include <uuid/uuid.h>

static void send_new_team_created(int fd, server_t *server, db_team_t *new_team)
{
    reply_data_t reply_data = {0};

    reply_data.type = NEW_TEAM_CREATED;
    memcpy(reply_data.arg1.team_uuid, new_team->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.team_name, new_team->name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg3.team_description, new_team->description, MAX_DESCRIPTION_LENGTH);
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd > 0) {
            send(server->clients[i].fd, &reply_data, sizeof(reply_data_t), 0);
        }
    }
    reply_data.type = REPLY_CREATE_TEAM_CMD;
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

void create_new_team(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_team_t *new_team = NULL;
    uuid_t team_uuid = {0};

    if (db_contain_team_name(&server->database, cmd_data->arg1.team_name)) {
        send_error_already_exist(client->fd);
    } else {
        new_team = my_calloc(sizeof(db_team_t));
        memcpy(new_team->name, cmd_data->arg1.team_name, MAX_NAME_LENGTH);
        memcpy(new_team->description, cmd_data->arg2.team_description, MAX_DESCRIPTION_LENGTH);
        uuid_generate_random(team_uuid);
        uuid_unparse(team_uuid, new_team->uuid);
        append_node(&server->database.team_list, create_node(new_team));
        SERVER_EVENT_TEAM_CREATED(new_team->uuid, new_team->name, client->uuid);
        send_new_team_created(client->fd, server, new_team);
    }
}
