/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** command_list
*/

#include "command_list.h"
#include "myteams_client.h"

const command_list_t command_list[] = {
    {HELP, "/help", 0, init_help},
    {LOGIN, "/login", 1, init_login},
    {LOGOUT, "/logout", 0, init_logout},
    {USERS, "/users", 0, init_users},
    {USER, "/user", 1, init_user},
    {SEND, "/send", 2, init_send},
    {MESSAGES, "/messages", 1, init_messages},
    {SUBSCRIBE, "/subscribe", 1, init_subscribe},
    {SUBSCRIBED, "/subscribed", 1, init_subscribed},
    {UNSUBSCRIBE, "/unsubscribe", 0, init_unsubscribe},
    {USE, "/use", -1, init_use}, // can be: 0, 1, 2 or 3 arg
    {CREATE, "/create", -1, init_create}, // can be: 1 if context are IN_THREAD or 2 otherwise;
    {LIST, "/list", 0, init_list},
    {INFO, "/info", 0, init_info},
};

context_e context;
