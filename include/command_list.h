/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** command_list
*/

#ifndef COMMAND_LIST_H_
    #define COMMAND_LIST_H_

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
    USE_TEAMS_UUID,
    USE_CHANNEL_UUID,
    USE_THREAD_UUID,
    CREATE_NEW_TEAM,
    CREATE_NEW_CHANNEL,
    CREATE_NEW_THREAD,
    CREATE_NEW_REPLY,
    LIST_TEAM,
    LIST_CHANNEL,
    LIST_THREAD,
    LIST_REPLY,
    INFO_LOGGED_IN_USER,
    INFO_CURRENT_TEAM_DETAILS,
    INFO_CURRENT_CHANNEL_DETAILS,
    INFO_CURRENT_THREAD_DETAILS
} command_e;

typedef struct {
    command_e index;
    char *name;
} command_list_t;

extern command_list_t command_list;

#endif /* !COMMAND_LIST_H_ */
