/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_list_reply_cmd
*/

#include "myteams_client.h"

void reply_list_reply_cmd(reply_data_t *reply_data)
{
    client_thread_print_replies(
        reply_data->arg1.thread_uuid,
        reply_data->arg2.user_uuid,
        reply_data->arg3.reply_timestamp,
        reply_data->arg4.reply_body
    );
}
