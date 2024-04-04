/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** cmd_handler
*/

#include "myteams_server.h"

void (*const cmd_handler[])(server_t *, client_t *, cmd_data_t *) = {
    [HELP] = NULL,
    [LOGIN] = cmd_login,
    [LOGOUT] = cmd_logout,
    [USERS] = cmd_users,
    [USER] = cmd_user,
    [SEND] = cmd_send,
    [MESSAGES] = cmd_messages,
    [SUBSCRIBE] = cmd_subscribe,
    [SUBSCRIBED] = cmd_subscribed,
    [UNSUBSCRIBE] = cmd_unsubscribe,
    [USE] = cmd_use,
    [CREATE] = cmd_create,
    [LIST] = cmd_list,
    [INFO] = cmd_info,
    [TREE] = cmd_tree
};
