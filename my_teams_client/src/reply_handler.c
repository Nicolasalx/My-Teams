/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_handler
*/

#include "myteams_client.h"
#include "reply_list.h"

void (*const reply_handler[])(reply_data_t *) = {
    [REPLY_LOGIN] = reply_login,
    [REPLY_LOGGED_OUT] = reply_logout,

    [PRIVATE_MSG_RECEIVED] = reply_msg_received,
    [NEW_THREAD_REPLY] = reply_thread_reply,
    [NEW_TEAM_CREATED] = reply_new_team_created,
    [NEW_CHANNEL_CREATED] = reply_new_channel_created,
    [NEW_THREAD_CREATED] = reply_new_thread_created,

    [REPLY_USERS_CMD] = reply_users_cmd,
    [REPLY_USER_CMD] = reply_user_cmd,
    [REPLY_MESSAGES_CMD] = reply_msg_cmd,
    [REPLY_LIST_TEAM_CMD] = reply_list_team_cmd,
    [REPLY_LIST_CHANNEL_CMD] = reply_list_channel_cmd,
    [REPLY_LIST_THREAD_CMD] = reply_list_thread_cmd,
    [REPLY_LIST_REPLY_CMD] = reply_list_reply_cmd,

    [ERROR_UNKNOWN_TEAM] = reply_error_unknow_team,
    [ERROR_UNKNOWN_CHANNEL] = reply_error_unknow_channel,
    [ERROR_UNKNOWN_THREAD] = reply_error_unknow_thread,
    [ERROR_UNKNOWN_USER] = reply_unknow_user,
    [ERROR_ALREADY_EXIST] = reply_error_already_exist,

    [REPLY_SUBSCRIBE_CMD] = reply_subscribe_cmd,
    [REPLY_SUBSCRIBED_TEAM_CMD] = reply_subscribed_team_cmd,
    [REPLY_SUBSCRIBED_USER_CMD] = reply_subscribed_user_cmd,
    [REPLY_UNSUBSCRIBE_CMD] = reply_unsubscribe_cmd,

    [REPLY_INFO_USER_CMD] = reply_info_user_cmd,
    [REPLY_INFO_TEAM_CMD] = reply_info_team_cmd,
    [REPLY_INFO_CHANNEL_CMD] = reply_info_channel_cmd,
    [REPLY_INFO_THREAD_CMD] = reply_info_thread_cmd,

    [REPLY_CREATE_TEAM_CMD] = reply_create_team_cmd,
    [REPLY_CREATE_CHANNEL_CMD] = reply_create_channel_cmd,
    [REPLY_CREATE_THREAD_CMD] = reply_create_thread_cmd,
    [REPLY_CREATE_REPLY_CMD] = reply_create_reply_cmd
};
