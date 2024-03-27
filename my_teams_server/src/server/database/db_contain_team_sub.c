/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** db_contain_team_sub
*/

#include "server_database.h"

db_user_t *db_contain_team_sub(db_team_t *team, const char *user_uuid)
{
    node_t *current = team->subscribed_user_list;

    if (team->subscribed_user_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->uuid, user_uuid, UUID_LENGTH) == 0) {
            return current->data;
        }
        current = current->next;
    } while (current != team->subscribed_user_list);
    return NULL;
}
