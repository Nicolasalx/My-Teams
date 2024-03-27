/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** contain_user
*/

#include "server_database.h"

db_user_t *db_contain_user(database_t *database, const char *name)
{
    node_t *current = database->user_list;

    if (database->user_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_user_t)->user_name, name, MAX_NAME_LENGTH) == 0) {
            return current->data;
        }
        current = current->next;
    } while (current != database->user_list);
    return NULL;
}
