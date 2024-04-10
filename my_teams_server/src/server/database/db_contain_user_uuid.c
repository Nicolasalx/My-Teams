/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** db_contain_user_uuid
*/

#include "server_database.h"

db_user_t *db_contain_user_uuid(
    database_t *database, const char *user_uuid)
{
    node_t *current = database->user_list;

    if (database->user_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->uuid,
            user_uuid, MAX_NAME_LENGTH) == 0) {
            return current->data;
        }
        current = current->next;
    } while (current != database->user_list);
    return NULL;
}
