/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_subscribe
*/

#include "myteams_server.h"

void cmd_subscribe(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    db_team_t *team_to_sub = db_contain_team(&server->database, cmd_data->arg1.team_uuid);

    if (team_to_sub) {
        if (db_contain_team_sub(team_to_sub, client->uuid)) {
            db_user_t *sub_user = my_calloc(sizeof(db_user_t));
            memcpy(sub_user->user_name, client->user_name, MAX_NAME_LENGTH);
            memcpy(sub_user->uuid, client->uuid, UUID_LENGTH);
            append_node(&team_to_sub->subscribed_user_list, create_node(&sub_user));
        }
        server_event_user_subscribed(cmd_data->arg1.team_uuid, client->uuid);
        // TODO: send reply
    } else {
        // TODO: send error reply unknow team
    }
}
