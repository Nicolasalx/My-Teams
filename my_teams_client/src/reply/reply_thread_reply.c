/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_thread_reply
*/

#include "myteams_client.h"

void reply_thread_reply(reply_data_t *reply_data)
{
    client_event_thread_reply_received(
        reply_data->arg1.team_uuid,
        reply_data->arg2.thread_uuid,
        reply_data->arg3.user_uuid,
        reply_data->arg4.reply_body
    );
}
