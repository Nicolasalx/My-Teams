/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** create_new_reply
*/

#include "myteams_server.h"
#include <uuid/uuid.h>

static void send_event_reply(client_t *client, server_t *server,
    db_team_t *team, db_reply_t *new_reply)
{
    reply_data_t reply_data = {0};

    reply_data.type = NEW_THREAD_REPLY;
    memcpy(reply_data.arg1.team_uuid, team->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.thread_uuid,
        client->context.thread_uuid, UUID_LENGTH);
    memcpy(reply_data.arg3.user_uuid,
        client->uuid, UUID_LENGTH);
    memcpy(reply_data.arg4.reply_body,
        new_reply->body, MAX_BODY_LENGTH);
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd > 0
        && db_contain_team_sub(team, server->clients[i].uuid)) {
            send_reply_to_client(server->clients[i].fd, &reply_data);
        }
    }
}

static void send_new_reply_created(client_t *client, server_t *server,
    db_team_t *team, db_reply_t *new_reply)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_CREATE_REPLY_CMD;
    memcpy(reply_data.arg1.thread_uuid,
        client->context.thread_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_uuid, client->uuid, UUID_LENGTH);
    memcpy(&reply_data.arg3.reply_timestamp,
        &new_reply->timestamp, sizeof(time_t));
    memcpy(reply_data.arg4.reply_body, new_reply->body, MAX_BODY_LENGTH);
    send_reply_to_client(client->fd, &reply_data);
    send_event_reply(client, server, team, new_reply);
}

static void fill_new_reply(db_reply_t *new_reply,
    client_t *client, cmd_data_t *cmd_data)
{
    uuid_t reply_uuid = {0};

    memcpy(new_reply->body, cmd_data->arg1.comment_body, MAX_BODY_LENGTH);
    memcpy(new_reply->creator_uuid, client->uuid, UUID_LENGTH);
    uuid_generate_random(reply_uuid);
    uuid_unparse(reply_uuid, new_reply->uuid);
    new_reply->timestamp = time(NULL);
    append_node(&GET_DATA(client->context.thread_ptr,
        db_thread_t)->reply_list, create_node(new_reply));
}

void create_new_reply(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_reply_t *new_reply = NULL;

    if (!is_valid_context(client)) {
        return;
    }
    if (!db_contain_team_sub(GET_DATA(client->context.team_ptr,
        db_team_t), client->uuid)) {
        send_error_unauthorized(client->fd);
        return;
    }
    new_reply = my_calloc(sizeof(db_reply_t));
    fill_new_reply(new_reply, client, cmd_data);
    server_event_reply_created(
        client->context.thread_uuid, client->uuid, new_reply->body);
    send_new_reply_created(client, server,
        GET_DATA(client->context.team_ptr, db_team_t), new_reply);
}
