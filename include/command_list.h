/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** command_list
*/

#ifndef COMMAND_LIST_H_
    #define COMMAND_LIST_H_

    #include <stddef.h>

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
    UNSUBSCRIBE,
    USE,
    CREATE,
    LIST,
    INFO,
    TREE,
    LATENCY,
    NUMBER_CMD // Used to determine the number of command
} command_t;

typedef enum {
    NO_CONTEXT,
    IN_TEAM,
    IN_CHANNEL,
    IN_THREAD
} context_enum_t;

typedef enum {
    NOT_LOGGED,
    LOGGED_IN
} is_login_t;

typedef enum {
    NO_COMMAND,
    COMMAND_FAILED,
    COMMAND_SUCCEED
} command_type_t;

typedef union {
    char user_name[MAX_NAME_LENGTH + 1];
    char user_uuid[UUID_LENGTH + 1];
    char team_uuid[UUID_LENGTH + 1];
    char team_name[MAX_NAME_LENGTH + 1];
    char channel_name[MAX_NAME_LENGTH + 1];
    char thread_title[MAX_NAME_LENGTH + 1];
    char comment_body[MAX_BODY_LENGTH + 1];
} cmd_arg1_t;

typedef union {
    char message_body[MAX_BODY_LENGTH + 1];
    char channel_uuid[UUID_LENGTH + 1];
    char team_description[MAX_DESCRIPTION_LENGTH + 1];
    char channel_description[MAX_DESCRIPTION_LENGTH + 1];
    char thread_message[MAX_BODY_LENGTH + 1];
} cmd_arg2_t;

typedef union {
    char thread_uuid[UUID_LENGTH + 1];
} cmd_arg3_t;

typedef union {
    size_t nb_arg;
} cmd_arg4_t;

typedef struct {
    command_t type;
    cmd_arg1_t arg1;
    cmd_arg2_t arg2;
    cmd_arg3_t arg3;
    cmd_arg4_t arg4;
} cmd_data_t;

typedef struct {
    char *name;
    command_type_t (*cmd_function)(char **, int, cmd_data_t *, command_t);
    command_t type;
    int nb_arg;
} command_list_t;

extern const command_list_t command_list[];

#endif /* !COMMAND_LIST_H_ */
