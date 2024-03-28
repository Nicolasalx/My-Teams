/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_info
*/

#include "myteams_server.h"

static void info_current_user(server_t *server, client_t *client)
{
    reply_data_t reply_data = {0};
    int is_connected = is_user_connected(server, client->uuid);

    reply_data.type = REPLY_INFO_USER_CMD;
    memcpy(reply_data.arg1.user_uuid, client->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_name, client->user_name, MAX_NAME_LENGTH);
    memcpy(&reply_data.arg3.user_status, &is_connected, sizeof(int));
    send(client->fd, &reply_data, sizeof(reply_data_t), 0);
}

static void info_current_team(client_t *client)
{
    reply_data_t reply_data = {0};

    if (!client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return;
    }
    reply_data.type = REPLY_INFO_TEAM_CMD;
    memcpy(reply_data.arg1.team_uuid, GET_DATA(client->context.team_ptr, db_team_t)->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.team_name, GET_DATA(client->context.team_ptr, db_team_t)->name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg3.team_description, GET_DATA(client->context.team_ptr, db_team_t)->description, MAX_DESCRIPTION_LENGTH);
    send(client->fd, &reply_data, sizeof(reply_data_t), 0);
}

static void info_current_channel(client_t *client)
{
    reply_data_t reply_data = {0};

    if (!client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return;
    }
    if (!client->context.channel_ptr) {
        send_error_unknown_channel(client->fd, client->context.channel_uuid);
        return;
    }
    reply_data.type = REPLY_INFO_CHANNEL_CMD;
    memcpy(reply_data.arg1.channel_uuid, GET_DATA(client->context.channel_ptr, db_channel_t)->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.channel_name, GET_DATA(client->context.channel_ptr, db_channel_t)->name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg3.channel_description, GET_DATA(client->context.channel_ptr, db_channel_t)->description, MAX_DESCRIPTION_LENGTH);
    send(client->fd, &reply_data, sizeof(reply_data_t), 0);
}

static void info_current_thread(client_t *client)
{
    reply_data_t reply_data = {0};

    if (!client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return;
    }
    if (!client->context.channel_ptr) {
        send_error_unknown_channel(client->fd, client->context.channel_uuid);
        return;
    }
    if (!client->context.thread_ptr) {
        send_error_unknown_thread(client->fd, client->context.thread_uuid);
        return;
    }
    reply_data.type = REPLY_INFO_THREAD_CMD;
    memcpy(reply_data.arg1.thread_uuid, GET_DATA(client->context.thread_ptr, db_thread_t)->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_uuid, GET_DATA(client->context.thread_ptr, db_thread_t)->creator_uuid, UUID_LENGTH);
    memcpy(&reply_data.arg3.thread_timestamp, &GET_DATA(client->context.thread_ptr, db_thread_t)->timestamp, sizeof(time_t));
    memcpy(reply_data.arg4.thread_title, GET_DATA(client->context.thread_ptr, db_thread_t)->name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg5.thread_body, GET_DATA(client->context.thread_ptr, db_thread_t)->body, MAX_BODY_LENGTH);
    send(client->fd, &reply_data, sizeof(reply_data_t), 0);
}

void cmd_info(server_t *server, client_t *client, cmd_data_t *)
{
    switch (client->context.type) {
    case NO_CONTEXT:
        info_current_user(server, client);
        break;
    case IN_TEAM:
        info_current_team(client);
        break;
    case IN_CHANNEL:
        info_current_channel(client);
        break;
    case IN_THREAD:
        info_current_thread(client);
        break;
    }
}
