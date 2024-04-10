/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_unsubscribe
*/

#include "myteams_server.h"

static void remove_subed_user(client_t *client, db_team_t *team_to_unsub)
{
    node_t *current = NULL;

    current = team_to_unsub->subscribed_user_list;
    if (team_to_unsub->subscribed_user_list == NULL) {
        return;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->uuid,
            client->uuid, UUID_LENGTH) == 0) {
            delete_node(&team_to_unsub->subscribed_user_list, current);
            return;
        }
        current = current->next;
    } while (current != team_to_unsub->subscribed_user_list);
}

static void send_unsubscribe_reply(int fd,
    const char *user_uuid, const char *team_uuid)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_UNSUBSCRIBE_CMD;
    memcpy(reply_data.arg1.user_uuid, user_uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.team_uuid, team_uuid, UUID_LENGTH);
    send_reply_to_client(fd, &reply_data);
}

void cmd_unsubscribe(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_team_t *team_to_unsub =
        db_contain_team(&server->database, cmd_data->arg1.team_uuid);

    if (!team_to_unsub) {
        send_error_unknown_team(client->fd, cmd_data->arg1.team_uuid);
        return;
    }
    server_event_user_unsubscribed(team_to_unsub->uuid, client->uuid);
    send_unsubscribe_reply(client->fd, client->uuid, cmd_data->arg1.team_uuid);
    remove_subed_user(client, team_to_unsub);
}
