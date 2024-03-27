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
        write(fd, current, size_data);
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
    close(fd);
}
