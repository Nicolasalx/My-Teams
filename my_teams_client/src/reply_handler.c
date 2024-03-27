/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_handler
*/

#include "myteams_client.h"
#include "reply_list.h"

void (*const reply_handler[])(reply_data_t *) = {
    [REPLY_LOGIN] = NULL,
    [REPLY_LOGGED_OUT] = NULL,
    [PRIVATE_MSG_RECEIVED] = NULL,
    [THREAD_REPLY] = NULL,
    [NEW_TEAM_CREATED] = NULL,
    [NEW_CHANNEL_CREATED] = NULL,
    [NEW_THREAD_CREATED] = NULL,
    [REPLY_USERS_CMD] = NULL,
    [REPLY_USER_CMD] = NULL,
    [REPLY_MESSAGES_CMD] = NULL,
    [REPLY_LIST_TEAM_CMD] = NULL,
    [REPLY_LIST_CHANNEL_CMD] = NULL,
    [REPLY_LIST_THREAD_CMD] = NULL,
    [REPLY_LIST_REPLY_CMD] = NULL,
    [ERROR_LIST_CHANNEL_CMD] = NULL,
    [ERROR_LIST_THREAD_CMD] = NULL,
    [ERROR_LIST_REPLY_CMD] = NULL
};
