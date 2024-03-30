/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_list
*/

#include "myteams_server.h"

static void list_team(server_t *server, client_t *client)
{
    node_t *current = server->database.team_list;
    reply_data_t reply_data = {0};

    if (server->database.team_list == NULL) {
        return;
    }
    do {
        reply_data.type = REPLY_LIST_TEAM_CMD;
        memcpy(reply_data.arg1.team_uuid, GET_DATA(current, db_team_t)->uuid, UUID_LENGTH);
        memcpy(reply_data.arg2.team_name, GET_DATA(current, db_team_t)->name, MAX_NAME_LENGTH);
        memcpy(reply_data.arg3.team_description, GET_DATA(current, db_team_t)->description, MAX_DESCRIPTION_LENGTH);
        send(client->fd, &reply_data, sizeof(reply_data_t), 0);
        current = current->next;
    } while (current != server->database.team_list);
}

static void list_channel(client_t *client)
{
    node_t *current = NULL;
    reply_data_t reply_data = {0};

    if (!client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return;
    }
    current = GET_DATA(client->context.team_ptr, db_team_t)->channel_list;
    if (current == NULL) {
        return;
    }
    do {
        reply_data.type = REPLY_LIST_CHANNEL_CMD;
        memcpy(reply_data.arg1.channel_uuid, GET_DATA(current, db_channel_t)->uuid, UUID_LENGTH);
        memcpy(reply_data.arg2.channel_name, GET_DATA(current, db_channel_t)->name, MAX_NAME_LENGTH);
        memcpy(reply_data.arg3.channel_description, GET_DATA(current, db_channel_t)->description, MAX_DESCRIPTION_LENGTH);
        send(client->fd, &reply_data, sizeof(reply_data_t), 0);
        current = current->next;
    } while (current != GET_DATA(client->context.team_ptr, db_team_t)->channel_list);
}

static void list_thread(client_t *client)
{
    node_t *current = NULL;
    reply_data_t reply_data = {0};

    if (!client->context.team_ptr) {
        send_error_unknown_team(client->fd, client->context.team_uuid);
        return;
    }
    if (!client->context.channel_ptr) {
        send_error_unknown_channel(client->fd, client->context.channel_uuid);
        return;
    }
    current = GET_DATA(client->context.channel_ptr, db_channel_t)->thread_list;
    if (current == NULL) {
        return;
    }
    do {
        reply_data.type = REPLY_LIST_THREAD_CMD;
        memcpy(reply_data.arg1.thread_uuid, GET_DATA(current, db_thread_t)->uuid, UUID_LENGTH);
        memcpy(reply_data.arg2.user_uuid, GET_DATA(current, db_thread_t)->creator_uuid, UUID_LENGTH);
        memcpy(&reply_data.arg3.thread_timestamp, &GET_DATA(current, db_thread_t)->timestamp, sizeof(time_t));
        memcpy(reply_data.arg4.thread_title, GET_DATA(current, db_thread_t)->name, MAX_NAME_LENGTH);
        memcpy(reply_data.arg5.thread_body, GET_DATA(current, db_thread_t)->body, MAX_BODY_LENGTH);
        send(client->fd, &reply_data, sizeof(reply_data_t), 0);
        current = current->next;
    } while (current != GET_DATA(client->context.channel_ptr, db_channel_t)->thread_list);
}

static void list_reply(client_t *client)
{
    node_t *current = NULL;
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
    current = GET_DATA(client->context.thread_ptr, db_thread_t)->reply_list;
    if (current == NULL) {
        return;
    }
    do {
        reply_data.type = REPLY_LIST_REPLY_CMD;
        memcpy(reply_data.arg1.thread_uuid, GET_DATA(current, db_reply_t)->uuid, UUID_LENGTH);
        memcpy(reply_data.arg2.user_uuid, GET_DATA(current, db_reply_t)->creator_uuid, UUID_LENGTH);
        memcpy(&reply_data.arg3.reply_timestamp, &GET_DATA(current, db_reply_t)->timestamp, sizeof(time_t));
        memcpy(reply_data.arg4.reply_body, GET_DATA(current, db_reply_t)->body, MAX_BODY_LENGTH);
        send(client->fd, &reply_data, sizeof(reply_data_t), 0);
        current = current->next;
    } while (current != GET_DATA(client->context.thread_ptr, db_thread_t)->reply_list);
}

void cmd_list(server_t *server, client_t *client, cmd_data_t *)
{
    switch (client->context.type) {
    case NO_CONTEXT:
        list_team(server, client);
        break;
    case IN_TEAM:
        list_channel(client);
        break;
    case IN_CHANNEL:
        list_thread(client);
        break;
    case IN_THREAD:
        list_reply(client);
        break;
    }
}
