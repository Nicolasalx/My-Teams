/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_subscribed
*/

#include "myteams_server.h"

static void send_subed_team(int fd, const char *team_uuid,
    const char *team_name, const char *team_description)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_SUBSCRIBED_TEAM_CMD;
    memcpy(reply_data.arg1.team_uuid, team_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.team_name, team_name, MAX_NAME_LENGTH);
    memcpy(reply_data.arg3.team_description, team_description, MAX_DESCRIPTION_LENGTH);
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

static void list_subed_team(server_t *server, client_t *client)
{
    node_t *current = server->database.team_list;

    if (server->database.team_list == NULL) {
        return;
    }
    do {
        if (db_contain_team_sub(GET_DATA(current, db_team_t), client->uuid)) {
            send_subed_team(client->fd,
                GET_DATA(current, db_team_t)->uuid,
                GET_DATA(current, db_team_t)->name,
                GET_DATA(current, db_team_t)->description);
        }
        current = current->next;
    } while (current != server->database.team_list);
}

static void send_subed_user(int fd, const char *user_uuid,
    const char *user_name, int user_status)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_SUBSCRIBED_USER_CMD;
    memcpy(reply_data.arg1.user_uuid, user_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_name, user_name, MAX_NAME_LENGTH);
    memcpy(&reply_data.arg3.user_status, &user_status, sizeof(int));
    send(fd, &reply_data, sizeof(reply_data_t), 0);
}

static void list_user_team_sub(server_t *server, db_team_t *team,
    const char *team_uuid, client_t *client)
{
    node_t *current = NULL;

    if (team == NULL) {
        send_error_unknown_team(client->fd, team_uuid);
        return;
    }
    current = team->subscribed_user_list;
    if (team->subscribed_user_list == NULL) {
        return;
    }
    do {
        send_subed_user(client->fd,
            GET_DATA(current, db_user_t)->uuid,
            GET_DATA(current, db_user_t)->user_name,
            is_user_connected(server, GET_DATA(current, db_user_t)->uuid));
        current = current->next;
    } while (current != team->subscribed_user_list);
}

void cmd_subscribed(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    if (cmd_data->arg4.nb_arg == 0) {
        list_subed_team(server, client);
    } else {
        list_user_team_sub(
            server,
            db_contain_team(&server->database, cmd_data->arg1.team_uuid),
            cmd_data->arg1.team_uuid, client);
    }
}
