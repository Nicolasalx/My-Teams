/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** create_new_channel
*/

#include "myteams_server.h"
#include <uuid/uuid.h>

static void send_new_channel_created(int fd,
    server_t *server, db_team_t *team, db_channel_t *new_channel)
{
    reply_data_t reply_data = {0};

    memcpy(reply_data.arg1.channel_uuid, new_channel->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.channel_name, new_channel->name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg3.channel_description,
        new_channel->description, MAX_DESCRIPTION_LENGTH);
    reply_data.type = REPLY_CREATE_CHANNEL_CMD;
    send_reply_to_client(fd, &reply_data);
    reply_data.type = NEW_CHANNEL_CREATED;
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd > 0
        && db_contain_team_sub(team, server->clients[i].uuid)) {
            send_reply_to_client(server->clients[i].fd, &reply_data);
        }
    }
}

static void fill_new_channel(server_t *server,
    client_t *client, cmd_data_t *cmd_data)
{
    db_channel_t *new_channel = my_calloc(sizeof(db_channel_t));
    uuid_t channel_uuid = {0};

    if (db_contain_channel_name(GET_DATA(client->context.team_ptr,
        db_team_t), cmd_data->arg1.channel_name)) {
        send_error_already_exist(client->fd);
    } else {
        memcpy(new_channel->name,
            cmd_data->arg1.channel_name, MAX_NAME_LENGTH);
        memcpy(new_channel->description,
            cmd_data->arg2.channel_description, MAX_DESCRIPTION_LENGTH);
        uuid_generate_random(channel_uuid);
        uuid_unparse(channel_uuid, new_channel->uuid);
        append_node(&GET_DATA(client->context.team_ptr,
            db_team_t)->channel_list, create_node(new_channel));
        server_event_channel_created(client->context.team_uuid,
            new_channel->uuid, new_channel->name);
        send_new_channel_created(client->fd, server,
            GET_DATA(client->context.team_ptr, db_team_t), new_channel);
    }
}

void create_new_channel(
    server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    if (!is_valid_context(client)) {
        return;
    }
    if (!db_contain_team_sub(GET_DATA(client->context.team_ptr,
        db_team_t), client->uuid)) {
        send_error_unauthorized(client->fd);
        return;
    }
    fill_new_channel(server, client, cmd_data);
}
