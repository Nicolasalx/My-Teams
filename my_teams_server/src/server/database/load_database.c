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

    if (read(fd, &nb_user, sizeof(size_t)) != sizeof(size_t)) {
        return true;
    }
    for (size_t i = 0; i < nb_user; ++i) {
        db_user = my_calloc(sizeof(db_user_t));
        if (read(fd, db_user, sizeof(db_user_t)) != sizeof(db_user_t)) {
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

    if (read(fd, &nb_elem, sizeof(size_t)) != sizeof(size_t)) {
        return true;
    }
    for (size_t i = 0; i < nb_elem; ++i) {
        db_data = my_calloc(data_size);
        if (read(fd, db_data, data_size) != (ssize_t) data_size) {
            return true;
        }
        append_node(list, create_node(db_data));
    }
    return false;
}

static bool load_thread(int fd, node_t **thread_list)
{
    size_t nb_thread = 0;
    db_thread_t *db_thread = NULL;

    if (read(fd, &nb_thread, sizeof(size_t)) != sizeof(size_t)) {
        return true;
    }
    for (size_t i = 0; i < nb_thread; ++i) {
        db_thread = my_calloc(sizeof(db_thread_t));
        if (read(fd, db_thread, sizeof(db_thread_t)) != sizeof(db_thread_t)) {
            return true;
        }
        db_thread->reply_list = NULL;
        append_node(thread_list, create_node(db_thread));
        if (load_linked_list(fd, &GET_DATA((*thread_list)->prev, db_thread_t)->reply_list, sizeof(db_reply_t))) {
            return true;
        }
    }
    return false;
}

static bool load_channel(int fd, node_t **channel_list)
{
    size_t nb_channel = 0;
    db_channel_t *db_channel = NULL;

    if (read(fd, &nb_channel, sizeof(size_t)) != sizeof(size_t)) {
        return true;
    }
    for (size_t i = 0; i < nb_channel; ++i) {
        db_channel = my_calloc(sizeof(db_channel_t));
        if (read(fd, db_channel, sizeof(db_channel_t)) != sizeof(db_channel_t)) {
            return true;
        }
        db_channel->thread_list = NULL;
        append_node(channel_list, create_node(db_channel));
        if (load_thread(fd, &GET_DATA((*channel_list)->prev, db_channel_t)->thread_list)) {
            return true;
        }
    }
    return false;
}

static bool load_team(int fd, node_t **team_list)
{
    size_t nb_team = 0;
    db_team_t *db_team = NULL;

    if (read(fd, &nb_team, sizeof(size_t)) != sizeof(size_t)) {
        return true;
    }
    for (size_t i = 0; i < nb_team; ++i) {
        db_team = my_calloc(sizeof(db_team_t));
        if (read(fd, db_team, sizeof(db_team_t)) != sizeof(db_team_t)) {
            return true;
        }
        db_team->channel_list = NULL;
        db_team->subscribed_user_list = NULL;
        append_node(team_list, create_node(db_team));
        if (load_linked_list(fd, &GET_DATA((*team_list)->prev, db_team_t)->subscribed_user_list, sizeof(db_user_t))) {
            return true;
        }
        if (load_channel(fd, &GET_DATA((*team_list)->prev, db_team_t)->channel_list)) {
            return true;
        }
    }
    return false;
}

void load_database(database_t *database)
{
    int fd = open("myteams.save", O_RDONLY);

    if (fd == -1) {
        return;
    }
    if (load_user_list(fd, &database->user_list)
    || load_linked_list(fd, &database->private_msg_list, sizeof(db_private_msg_t))
    || load_team(fd, &database->team_list)) {
        printf(MAGENTA("Warning: Corrupted database")"\n");
        memset(database, 0, sizeof(database_t));
    }
    close(fd);
}
