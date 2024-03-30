/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** create_new_thread
*/

#include "myteams_server.h"
#include <uuid/uuid.h>

static void send_new_thread_created(client_t *client, server_t *server, db_team_t *team, db_thread_t *new_thread)
{
    reply_data_t reply_data = {0};

    memcpy(reply_data.arg1.thread_uuid, new_thread->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_uuid, client->uuid, UUID_LENGTH);
    memcpy(&reply_data.arg3.thread_timestamp, &new_thread->timestamp, sizeof(time_t));
    memcpy(reply_data.arg4.thread_title, new_thread->name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg5.thread_body, new_thread->body, MAX_BODY_LENGTH);
    reply_data.type = REPLY_CREATE_THREAD_CMD;
    send(client->fd, &reply_data, sizeof(reply_data_t), 0);

    reply_data.type = NEW_THREAD_CREATED;
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd > 0 && db_contain_team_sub(team, server->clients[i].uuid)) {
            send(server->clients[i].fd, &reply_data, sizeof(reply_data_t), 0);
        }
    }
}

void create_new_thread(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_thread_t *new_thread = NULL;
    uuid_t thread_uuid = {0};

    if (!client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return;
    }
    if (!client->context.channel_ptr) {
        send_error_unknown_channel(client->fd, client->context.channel_uuid);
        return;
    }
    if (!db_contain_team_sub(GET_DATA(client->context.team_ptr, db_team_t), client->uuid)) {
        send_error_unauthorized(client->fd);
        return;
    }
    if (db_contain_thread_name(GET_DATA(client->context.channel_ptr, db_channel_t), cmd_data->arg1.thread_title)) {
        send_error_already_exist(client->fd);
    } else {
        new_thread = my_calloc(sizeof(db_thread_t));

        memcpy(new_thread->name, cmd_data->arg1.thread_title, MAX_NAME_LENGTH);
        memcpy(new_thread->body, cmd_data->arg2.thread_message, MAX_BODY_LENGTH);
        memcpy(new_thread->creator_uuid, client->uuid, UUID_LENGTH);
        uuid_generate_random(thread_uuid);
        uuid_unparse(thread_uuid, new_thread->uuid);
        new_thread->timestamp = time(NULL);
        append_node(&GET_DATA(client->context.channel_ptr, db_channel_t)->thread_list, create_node(new_thread));

        SERVER_EVENT_THREAD_CREATED(client->context.channel_uuid,
            new_thread->uuid, client->uuid, new_thread->name, new_thread->body);
        send_new_thread_created(client, server, GET_DATA(client->context.team_ptr, db_team_t), new_thread);
    }
}
