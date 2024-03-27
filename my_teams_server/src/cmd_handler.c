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
    [LOGOUT] = NULL,
    [USERS] = NULL,
    [USER] = NULL,
    [SEND] = NULL,
    [MESSAGES] = NULL,
    [SUBSCRIBE] = NULL,
    [SUBSCRIBED] = NULL,
    [UNSUBSCRIBE] = NULL,
    [USE] = NULL,
    [CREATE] = NULL,
    [LIST] = NULL,
    [INFO] = NULL
};
