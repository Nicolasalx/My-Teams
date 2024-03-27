/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** command_list
*/

#include "command_list.h"

const command_list_t command_list[] = {
    {HELP, "/help", 0},
    {LOGIN, "/login", 1},
    {LOGOUT, "logout", 0},
    {USERS, "/users", 0},
    {USER, "/user", 1},
    {SEND, "/send", 2},
    {MESSAGES, "/messages", 1},
    {SUBSCRIBE, "/subscribe", 1},
    {SUBSCRIBED, "/subscribed", 0},
    {SUBSCRIBED_TEAM_UUID, "/subscribed", 1},
    {UNSUBSCRIBE, "/unsubscribe", 0},
    {USE, "/use", -1}, // can be: 0, 1, 2 or 3 arg
    {CREATE, "/create", -1}, // can be: 1 if context are IN_THREAD or 2 otherwise;
    {LIST, "/list", 0},
    {INFO, "/info", 0},
};

const int size_cmd_list = sizeof(command_list) / sizeof(command_list_t);
