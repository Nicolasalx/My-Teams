/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** db_contain_thread
*/

#include "server_database.h"

db_thread_t *db_contain_thread_name(
    db_channel_t *db_channel, const char *thread_name)
{
    node_t *current = db_channel->thread_list;

    if (db_channel->thread_list == NULL) {
        return NULL;
    }
    do {
        if (memcmp(GET_DATA(current, db_thread_t)->name,
            thread_name, MAX_NAME_LENGTH) == 0) {
            return current->data;
        }
        current = current->next;
    } while (current != db_channel->thread_list);
    return NULL;
}
