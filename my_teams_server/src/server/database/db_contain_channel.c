/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** db_contain_channel_name
*/

#include "server_database.h"

db_channel_t *db_contain_channel_name(db_team_t *db_team, const char *channel_name)
{
    node_t *current = db_team->channel_list;

    if (db_team->channel_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_channel_t)->name, channel_name, MAX_NAME_LENGTH) == 0) {
            return current->data;
        }
        current = current->next;
    } while (current != db_team->channel_list);
    return NULL;
}
