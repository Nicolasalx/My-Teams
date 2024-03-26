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
    LOGIN, // client_event_logged_in
    LOGGED_OUT, // client_event_logged_out
    PRIVATE_MSG_RECEIVED, // client_event_private_message_received
    THREAD_REPLY, // client_event_thread_reply_received
    NEW_TEAM_CREATED, // client_event_team_created
    NEW_CHANNEL_CREATED, // client_event_channel_created
    NEW_THREAD_CREATED // client_event_thread_created
} reply_e;

typedef union {
    char user_uuid[UUID_LENGTH];
    char team_uuid[UUID_LENGTH];
    char channel_uuid[UUID_LENGTH];
    char thread_uuid[UUID_LENGTH];
} reply_arg1_u;

typedef union {
    char user_name[MAX_NAME_LENGTH];
    char message_body[MAX_BODY_LENGTH];
    char thread_uuid[UUID_LENGTH];
    char team_name[MAX_NAME_LENGTH];
    char channel_name[MAX_NAME_LENGTH];
    char user_uuid[UUID_LENGTH];
} reply_arg2_u;

typedef union {
    char user_uuid[UUID_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];
    time_t thread_timestamp;
} reply_arg3_u;

typedef union {
    char reply_body[MAX_BODY_LENGTH];
    char thread_title[MAX_NAME_LENGTH];
} reply_arg4_u;

typedef union {
    char thread_body[MAX_BODY_LENGTH];
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
