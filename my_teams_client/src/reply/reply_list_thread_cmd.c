/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_list_thread_cmd
*/

#include "myteams_client.h"

void reply_list_thread_cmd(reply_data_t *reply_data)
{
    client_channel_print_threads(
        reply_data->arg1.thread_uuid,
        reply_data->arg2.user_uuid,
        reply_data->arg3.thread_timestamp,
        reply_data->arg4.thread_title,
        reply_data->arg5.thread_body
    );
}
