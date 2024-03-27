/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_list
*/

#include "myteams_server.h"

static void list_team(server_t *server, client_t *client)
{
    node_t *current = server->database.team_list;

    if (server->database.team_list == NULL) {
        return;
    }
    do {
        // TODO: send team name
        current = current->next;
    } while (current != server->database.team_list);
}

static void list_team_channel(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    // TODO: send error if team don't exist
    node_t *current = server->database.team_list;

    if (server->database.team_list == NULL) {
        return;
    }
    do {
        // TODO: send channel name
        current = current->next;
    } while (current != server->database.team_list);
}

void cmd_list(server_t *server, client_t *client, cmd_data_t *cmd_data)
{
    switch (client->context.type) {
    case NO_CONTEXT:
        list_team(server, client);
        break;
    case IN_TEAM:
        list_team_channel(server, client, cmd_data);
        break;
    case IN_CHANNEL:
        /* code */
        break;
    case IN_THREAD:
        /* code */
        break;
    }

// TODO: reply & reply with error if invalid context
}
