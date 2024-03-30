/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** save_database
*/

#include "myteams_server.h"
#include <fcntl.h>

static void save_linked_list(int fd, node_t *list, size_t size_data)
{
    size_t nb_elem = my_listlen(list);
    node_t *current = list;

    write(fd, &nb_elem, sizeof(size_t));
    for (size_t i = 0; i < nb_elem; ++i) {
        printf("SAVE LL of size %zu\n", size_data);
        write(fd, current->data, size_data);
        current = current->next;
    }
}

static void save_thread(int fd, node_t *thread_list)
{
    size_t nb_thread = my_listlen(thread_list);
    node_t *current = thread_list;

    write(fd, &nb_thread, sizeof(size_t));
    for (size_t i = 0; i < nb_thread; ++i) {
        printf("SAVE THREAD\n");
        write(fd, current->data, sizeof(db_thread_t));
        save_linked_list(fd, GET_DATA(current, db_thread_t)->reply_list, sizeof(db_reply_t));
        current = current->next;
    }
}

static void save_channel(int fd, node_t *channel_list)
{
    size_t nb_channel = my_listlen(channel_list);
    node_t *current = channel_list;

    write(fd, &nb_channel, sizeof(size_t));
    for (size_t i = 0; i < nb_channel; ++i) {
        printf("SAVE CHANNEL\n");
        write(fd, current->data, sizeof(db_channel_t));
        save_thread(fd, GET_DATA(current, db_channel_t)->thread_list);
        current = current->next;
    }
}

static void save_team(int fd, node_t *team_list)
{
    size_t nb_team = my_listlen(team_list);
    node_t *current = team_list;

    write(fd, &nb_team, sizeof(size_t));
    for (size_t i = 0; i < nb_team; ++i) {
        printf("SAVE TEAM\n");
        write(fd, current->data, sizeof(db_team_t));
        save_linked_list(fd, GET_DATA(current, db_team_t)->subscribed_user_list, sizeof(db_user_t));
        save_channel(fd, GET_DATA(current, db_team_t)->channel_list);
        current = current->next;
    }
}

void save_database(database_t *database)
{
    int fd = open("myteams.save", O_TRUNC | O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        printf("Fail to save database.\n");
        return;
    }
    save_linked_list(fd, database->user_list, sizeof(db_user_t));
    save_linked_list(fd, database->private_msg_list, sizeof(db_private_msg_t));
    save_team(fd, database->team_list);
    close(fd);
}
