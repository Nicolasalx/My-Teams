/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_list
*/

#ifndef REPLY_LIST_H_
    #define REPLY_LIST_H_

    #include <time.h>
    #include "command_list.h"

typedef enum {
    REPLY_LOGIN, // client_event_logged_in
    REPLY_LOGGED_OUT, // client_event_logged_out
    PRIVATE_MSG_RECEIVED, // client_event_private_message_received
    THREAD_REPLY, // client_event_thread_reply_received
    NEW_TEAM_CREATED, // client_event_team_created
    NEW_CHANNEL_CREATED, // client_event_channel_created
    NEW_THREAD_CREATED, // client_event_thread_created
    REPLY_USERS_CMD, // client_print_users -> cmd "/users"
    REPLY_USER_CMD, // client_print_user -> cmd "/user"
    REPLY_MESSAGES_CMD, // client_private_message_print_messages -> cmd "/messages"
    REPLY_LIST_TEAM_CMD, // client_print_teams -> cmd "/list" -> NO_CONTEXT
    REPLY_LIST_CHANNEL_CMD, // client_team_print_channels -> cmd "/list" -> IN_TEAM         | client_error_unknown_team
    REPLY_LIST_THREAD_CMD, // client_channel_print_threads -> cmd "/list" -> IN_CHANNEL     | client_error_unknown_channel
    REPLY_LIST_REPLY_CMD, // client_thread_print_replies -> cmd "/list" -> IN_THREAD        | client_error_unknown_thread

    ERROR_UNKNOWN_TEAM, // !client_error_unknown_team
    ERROR_UNKNOWN_CHANNEL, // !client_error_unknown_channel
    ERROR_UNKNOWN_THREAD, // !client_error_unknown_thread
    ERROR_UNKNOWN_USER, // !client_error_unknown_user
    ERROR_ALREADY_EXIST, // !client_error_already_exist

    REPLY_SUBSCRIBE_CMD, // client_print_subscribed
    REPLY_SUBSCRIBED_TEAM_CMD, // client_print_teams
    REPLY_SUBSCRIBED_USER_CMD, // client_print_users
    REPLY_UNSUBSCRIBE_CMD, // client_print_unsubscribed

    REPLY_INFO_USER_CMD, // client_print_user
    REPLY_INFO_TEAM_CMD, // client_print_team
    REPLY_INFO_CHANNEL_CMD, // client_print_channel
    REPLY_INFO_THREAD_CMD, // client_print_thread

    NUMBER_REPLY
} reply_e;

typedef union {
    char sender_uuid[UUID_LENGTH + 1];
    char user_uuid[UUID_LENGTH + 1];
    char team_uuid[UUID_LENGTH + 1];
    char channel_uuid[UUID_LENGTH + 1];
    char thread_uuid[UUID_LENGTH + 1];
} reply_arg1_u;

typedef union {
    time_t message_timestamp;
    char team_uuid[UUID_LENGTH + 1];
    char user_name[MAX_NAME_LENGTH + 1];
    char message_body[MAX_BODY_LENGTH + 1];
    char thread_uuid[UUID_LENGTH + 1];
    char team_name[MAX_NAME_LENGTH + 1];
    char channel_name[MAX_NAME_LENGTH + 1];
    char user_uuid[UUID_LENGTH + 1];
} reply_arg2_u;

typedef union {
    char message_body[MAX_BODY_LENGTH + 1];
    time_t reply_timestamp;
    char user_uuid[UUID_LENGTH + 1];
    char team_description[MAX_DESCRIPTION_LENGTH + 1];
    char channel_description[MAX_DESCRIPTION_LENGTH + 1];
    time_t thread_timestamp;
    int user_status;
} reply_arg3_u;

typedef union {
    char reply_body[MAX_BODY_LENGTH + 1];
    char thread_title[MAX_NAME_LENGTH + 1];
} reply_arg4_u;

typedef union {
    char thread_body[MAX_BODY_LENGTH + 1];
} reply_arg5_u;

typedef struct {
    reply_e type;
    reply_arg1_u arg1;
    reply_arg2_u arg2;
    reply_arg3_u arg3;
    reply_arg4_u arg4;
    reply_arg5_u arg5;
} reply_data_t;

#endif /* !REPLY_LIST_H_ */
