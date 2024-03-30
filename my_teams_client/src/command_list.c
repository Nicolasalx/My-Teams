/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** command_list
*/

#include "command_list.h"
#include "myteams_client.h"

const command_list_t command_list[] = {
    {
        .type = HELP,
        .name = "/help",
        .nb_arg = 0,
        .cmd_function = init_help
    }, {
        .type = LOGIN,
        .name = "/login",
        .nb_arg = 1,
        .cmd_function = init_login
    }, {
        .type = LOGOUT,
        .name = "/logout",
        .nb_arg = 0,
        .cmd_function = init_logout
    }, {
        .type = USERS,
        .name = "/users",
        .nb_arg = 0,
        .cmd_function = init_users
    }, {
        .type = USER,
        .name = "/user",
        .nb_arg = 1,
        .cmd_function = init_user
    }, {
        .type = SEND,
        .name = "/send",
        .nb_arg = 2,
        .cmd_function = init_send
    }, {
        .type = MESSAGES,
        .name = "/messages",
        .nb_arg = 1,
        .cmd_function = init_messages
    }, {
        .type = SUBSCRIBE,
        .name = "/subscribe",
        .nb_arg = 1,
        .cmd_function = init_subscribe
    }, {
        .type = SUBSCRIBED,
        .name = "/subscribed",
        .nb_arg = 1,
        .cmd_function = init_subscribed
    }, {
        .type = UNSUBSCRIBE,
        .name = "/unsubscribe",
        .nb_arg = 1,
        .cmd_function = init_unsubscribe
    }, {
        .type = USE,
        .name = "/use",
        .nb_arg = -1, // can be: 0, 1, 2 or 3 arg
        .cmd_function = init_use
    }, {
        .type = CREATE,
        .name = "/create",
        .nb_arg = -1, // can be: 1 if context are IN_THREAD or 2 otherwise;
        .cmd_function = init_create
    }, {
        .type = LIST,
        .name = "/list",
        .nb_arg = 0,
        .cmd_function = init_list
    }, {
        .type = INFO,
        .name = "/info",
        .nb_arg = 0,
        .cmd_function = init_info
    },
};

context_e context;
is_login_e isLogin = NOT_LOGGED;
