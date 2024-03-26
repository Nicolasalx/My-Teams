/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** load_database
*/

#include "myteams_server.h"
#include <fcntl.h>

static bool load_user_list(int fd, node_t **user_list)
{
    size_t nb_user = 0;
    db_user_t *db_user = NULL;

    if (read(fd, &nb_user, sizeof(size_t)) == -1) {
        return true;
    }
    for (size_t i = 0; i < nb_user; ++i) {
        db_user = my_calloc(sizeof(db_user_t));
        if (read(fd, db_user, sizeof(db_user_t)) == -1) {
            return true;
        }
        append_node(user_list, create_node(db_user));
        server_event_user_loaded(db_user->uuid, db_user->user_name);
    }
    return false;
}

static bool load_linked_list(int fd, node_t **list, size_t data_size)
{
    size_t nb_elem = 0;
    void *db_data = NULL;

    if (read(fd, &nb_elem, sizeof(size_t)) == -1) {
        return true;
    }
    for (size_t i = 0; i < nb_elem; ++i) {
        db_data = my_calloc(data_size);
        if (read(fd, &db_data, data_size) == -1) {
            return true;
        }
        append_node(list, create_node(db_data));
    }
    return false;
}

void load_database(database_t *database)
{
    int fd = open("myteams.save", O_RDONLY);

    if (fd == -1) {
        return;
    }
    (void) (load_user_list(fd, &database->user_list) ||
    load_linked_list(fd, &database->private_msg_list, sizeof(db_private_msg_t)));
    close(fd);
}
