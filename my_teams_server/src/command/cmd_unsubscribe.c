/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_unsubscribe
*/

#include "myteams_server.h"

void cmd_unsubscribe(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_team_t *team_to_unsub = db_contain_team(&server->database, cmd_data->arg1.team_uuid);
    node_t *current = NULL;

    if (!team_to_unsub) {
        // TODO: send reply error
        return;
    }
    server_event_user_unsubscribed(team_to_unsub->uuid, client->uuid);
    // TODO: send reply
    current = team_to_unsub->subscribed_user_list;
    if (team_to_unsub->subscribed_user_list == NULL) {
        return;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->uuid, client->uuid, UUID_LENGTH) == 0) {
            delete_node(&team_to_unsub->subscribed_user_list, current);
            return;
        }
        current = current->next;
    } while (current != team_to_unsub->subscribed_user_list);
}
