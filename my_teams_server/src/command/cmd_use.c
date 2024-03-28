/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_use
*/

#include "myteams_server.h"

static node_t *move_to_team_context(server_t *server, client_t *client)
{
    node_t *current = server->database.team_list;

    if (server->database.team_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_team_t)->uuid, client->context.team_uuid, UUID_LENGTH) == 0) {
            return current;
        }
        current = current->next;
    } while (current != server->database.team_list);
    return NULL;
}

static node_t *move_to_channel_context(client_t *client, node_t *current_team)
{
    node_t *current = NULL;

    if (!current_team || GET_DATA(current_team, db_team_t)->channel_list == NULL) {
        return NULL;
    }
    current = GET_DATA(current_team, db_team_t)->channel_list;
    do {
        if (memcmp(GET_DATA(current, db_channel_t)->uuid, client->context.channel_uuid, UUID_LENGTH) == 0) {
            return current;
        }
        current = current->next;
    } while (current != GET_DATA(current_team, db_team_t)->channel_list);
    return NULL;
}

static node_t *move_to_thread_context(client_t *client, node_t *current_channel)
{
    node_t *current = NULL;

    if (!current_channel || GET_DATA(current_channel, db_channel_t)->thread_list == NULL) {
        return NULL;
    }
    current = GET_DATA(current_channel, db_channel_t)->thread_list;
    do {
        if (memcmp(GET_DATA(current, db_thread_t)->uuid, client->context.thread_uuid, UUID_LENGTH) == 0) {
            return current;
        }
        current = current->next;
    } while (current != GET_DATA(current_channel, db_channel_t)->thread_list);
    return NULL;
}

void cmd_use(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    memcpy(client->context.team_uuid, cmd_data->arg1.team_uuid, UUID_LENGTH);
    memcpy(client->context.channel_uuid, cmd_data->arg2.channel_uuid, UUID_LENGTH);
    memcpy(client->context.thread_uuid, cmd_data->arg3.thread_uuid, UUID_LENGTH);
    client->context.type = cmd_data->arg4.nb_arg;
    switch (client->context.type) {
    case IN_TEAM:
        client->context.team_ptr = move_to_team_context(server, client);
        break;
    case IN_CHANNEL:
        client->context.team_ptr = move_to_team_context(server, client);
        client->context.channel_ptr = move_to_channel_context(client, client->context.team_ptr);
        break;
    case IN_THREAD:
        client->context.team_ptr = move_to_team_context(server, client);
        client->context.channel_ptr = move_to_channel_context(client, client->context.team_ptr);
        client->context.thread_ptr = move_to_thread_context(client, client->context.channel_ptr);
        break;
    default:
        memset(&client->context, 0, sizeof(context_t));
        break;
    }
}
