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
} db_private_msg_t;

typedef struct {
    node_t *user_list;
    node_t *private_msg_list;
} database_t;

void save_database(database_t *database);
void load_database(database_t *database);

db_user_t *db_contain_user(database_t *database, const char *name);

#endif /* !SERVER_DATABASE_H_ */
