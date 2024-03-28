/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** server_database
*/

#ifndef SERVER_DATABASE_H_
    #define SERVER_DATABASE_H_

    #include "my_importall.h"
    #include "command_list.h"

typedef struct {
    char uuid[UUID_LENGTH + 1];
    char user_name[MAX_NAME_LENGTH + 1];
} db_user_t;

typedef struct {
    char sender_uuid[UUID_LENGTH + 1];
    char receiver_uuid[UUID_LENGTH + 1];
    char msg[MAX_BODY_LENGTH + 1];
    time_t timestamp;
} db_private_msg_t;

typedef struct {
    char uuid[UUID_LENGTH + 1]; // ! maybe unused
    char body[MAX_BODY_LENGTH + 1];
    char creator_uuid[UUID_LENGTH + 1];
    time_t timestamp;
} db_reply_t;

typedef struct {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];
    time_t timestamp;
    char creator_uuid[UUID_LENGTH + 1];
    node_t *reply_list;
} db_thread_t;

typedef struct {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    node_t *thread_list;
} db_channel_t;

typedef struct {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    node_t *subscribed_user_list;
    node_t *channel_list;
} db_team_t;

typedef struct {
    node_t *user_list;
    node_t *private_msg_list;
    node_t *team_list;
} database_t;

void save_database(database_t *database);
void load_database(database_t *database);

db_user_t *db_contain_user(database_t *database, const char *name);
db_user_t *db_contain_user_uuid(database_t *database, const char *user_uuid);
db_team_t *db_contain_team(database_t *database, const char *team_uuid);
db_team_t *db_contain_team_name(database_t *database, const char *team_name);
db_user_t *db_contain_team_sub(db_team_t *team, const char *user_uuid);
db_channel_t *db_contain_channel_name(db_team_t *db_team, const char *channel_name);
db_thread_t *db_contain_thread_name(db_channel_t *db_channel, const char *thread_name);

#endif /* !SERVER_DATABASE_H_ */
