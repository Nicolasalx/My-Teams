/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** command_list
*/

#ifndef COMMAND_LIST_H_
    #define COMMAND_LIST_H_

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define UUID_LENGTH 36

typedef enum {
    HELP,
    LOGIN,
    LOGOUT,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    SUBSCRIBED_TEAM_UUID,
    UNSUBSCRIBE,
    USE,
    CREATE,
    LIST,
    INFO
} command_e;

typedef struct {
    command_e type;
    char *name;
    int nb_arg;
} command_list_t;

extern command_list_t command_list;

typedef enum {
    NO_CONTEXT,
    IN_TEAM,
    IN_CHANNEL,
    IN_THREAD
} context_e;

typedef union {
    char user_name[MAX_NAME_LENGTH];
    char user_uuid[UUID_LENGTH];
    char team_uuid[UUID_LENGTH];
    char team_name[MAX_NAME_LENGTH];
    char channel_name[MAX_NAME_LENGTH];
    char thread_title[MAX_NAME_LENGTH];
    char comment_body[MAX_BODY_LENGTH];
} arg1_u;

typedef union {
    char message_body[MAX_BODY_LENGTH];
    char channel_uuid[UUID_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];
    char thread_message[MAX_BODY_LENGTH];
} arg2_u;

typedef union {
    char thread_uuid[UUID_LENGTH];
} arg3_u;

typedef struct {
    command_e type;
    arg1_u arg1;
    arg2_u arg2;
    arg3_u arg3;
} cmd_data_t;

#endif /* !COMMAND_LIST_H_ */
