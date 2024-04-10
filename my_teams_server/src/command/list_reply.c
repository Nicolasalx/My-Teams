/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** list_reply
*/

#include "myteams_server.h"

static void send_list_reply(client_t *client, node_t *current)
{
    reply_data_t reply_data = {0};

    reply_data.type = REPLY_LIST_REPLY_CMD;
    memcpy(reply_data.arg1.thread_uuid,
        GET_DATA(current, db_reply_t)->uuid, UUID_LENGTH);
    memcpy(reply_data.arg2.user_uuid,
        GET_DATA(current, db_reply_t)->creator_uuid, UUID_LENGTH);
    memcpy(&reply_data.arg3.reply_timestamp,
        &GET_DATA(current, db_reply_t)->timestamp, sizeof(time_t));
    memcpy(reply_data.arg4.reply_body,
        GET_DATA(current, db_reply_t)->body, MAX_BODY_LENGTH);
    send_reply_to_client(client->fd, &reply_data);
}

void list_reply(client_t *client)
{
    node_t *current = NULL;

    if (!is_valid_context(client)) {
        return;
    }
    current = GET_DATA(client->context.thread_ptr,
        db_thread_t)->reply_list;
    if (current == NULL) {
        return;
    }
    do {
        send_list_reply(client, current);
        current = current->next;
    } while (current !=
        GET_DATA(client->context.thread_ptr, db_thread_t)->reply_list);
}
