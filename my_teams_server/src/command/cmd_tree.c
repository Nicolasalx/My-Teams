/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_tree
*/

#include "myteams_server.h"

static void print_reply(int fd, node_t *list)
{
    size_t nb_reply = my_listlen(list);
    node_t *current = list;
    reply_data_t reply_data = {0};
    char msg_time[30] = {0};

    for (size_t i = 0; i < nb_reply; ++i) {
        reply_data.type = REPLY_STRING;
        memset(msg_time, 0, 30);
        strftime(msg_time, 30, "%H:%M:%S %d-%m-%Y", localtime(&GET_DATA(current, db_reply_t)->timestamp));
        if (i == nb_reply - 1) {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m│ \e[93m│ \e[95m│ \e[0m└─ \"%s\" - %s",
                GET_DATA(current, db_reply_t)->body, msg_time);
        } else {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m│ \e[93m│ \e[95m│ \e[0m├─ \"%s\" - %s",
                GET_DATA(current, db_reply_t)->body, msg_time);
        }
        send_reply_to_client(fd, &reply_data);
        memset(&reply_data, 0, sizeof(reply_data_t));

        current = current->next;
    }
}

static void print_thread(int fd, node_t *thread_list)
{
    size_t nb_thread = my_listlen(thread_list);
    node_t *current = thread_list;
    reply_data_t reply_data = {0};

    for (size_t i = 0; i < nb_thread; ++i) {
        reply_data.type = REPLY_STRING;
        if (i == nb_thread - 1) {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m│ \e[93m│ \e[95m└─\e[0m \"%s\" - \"%s\"",
                GET_DATA(current, db_thread_t)->name, GET_DATA(current, db_thread_t)->uuid);
        } else {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m│ \e[93m│ \e[95m├─\e[0m \"%s\" - \"%s\"",
                GET_DATA(current, db_thread_t)->name, GET_DATA(current, db_thread_t)->uuid);
        }
        send_reply_to_client(fd, &reply_data);
        memset(&reply_data, 0, sizeof(reply_data_t));

        print_reply(fd, GET_DATA(current, db_thread_t)->reply_list);
        current = current->next;
    }
}

static void print_channel(int fd, node_t *channel_list)
{
    size_t nb_channel = my_listlen(channel_list);
    node_t *current = channel_list;
    reply_data_t reply_data = {0};

    for (size_t i = 0; i < nb_channel; ++i) {
        reply_data.type = REPLY_STRING;
        if (i == nb_channel - 1) {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m│ \e[93m└─\e[0m \"%s\" - \"%s\"",
                GET_DATA(current, db_channel_t)->name, GET_DATA(current, db_channel_t)->uuid);
        } else {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m│ \e[93m├─\e[0m \"%s\" - \"%s\"",
                GET_DATA(current, db_channel_t)->name, GET_DATA(current, db_channel_t)->uuid);
        }
        send_reply_to_client(fd, &reply_data);
        memset(&reply_data, 0, sizeof(reply_data_t));

        print_thread(fd, GET_DATA(current, db_channel_t)->thread_list);
        current = current->next;
    }
}

// ┌, ─, ┐, └, ─, ┘, │, ├

static void print_team(int fd, node_t *team_list)
{
    size_t nb_team = my_listlen(team_list);
    node_t *current = team_list;
    reply_data_t reply_data = {0};

    for (size_t i = 0; i < nb_team; ++i) {
        reply_data.type = REPLY_STRING;
        if (i == nb_team - 1) {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m└─\e[0m \"%s\" - \"%s\"",
                GET_DATA(current, db_team_t)->name, GET_DATA(current, db_team_t)->uuid);
        } else {
            snprintf((char *) &reply_data.arg1, sizeof(reply_data_t) - sizeof(reply_e),
                "\e[94m├─\e[0m \"%s\" - \"%s\"",
                GET_DATA(current, db_team_t)->name, GET_DATA(current, db_team_t)->uuid);
        }
        send_reply_to_client(fd, &reply_data);
        memset(&reply_data, 0, sizeof(reply_data_t));

        print_channel(fd, GET_DATA(current, db_team_t)->channel_list);
        current = current->next;
    }
}

void cmd_tree(server_t *server, client_t *client, cmd_data_t *)
{
    print_team(client->fd, server->database.team_list);
}
