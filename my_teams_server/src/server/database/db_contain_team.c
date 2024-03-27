/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** db_contain_team
*/

#include "server_database.h"

db_team_t *db_contain_team(database_t *database, const char *team_uuid)
{
    node_t *current = database->team_list;

    if (database->team_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_team_t)->uuid, team_uuid, UUID_LENGTH) == 0) {
            return current->data;
        }
        current = current->next;
    } while (current != database->team_list);
    return NULL;
}
