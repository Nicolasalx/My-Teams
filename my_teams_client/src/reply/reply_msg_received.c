/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_msg_received
*/

#include "myteams_client.h"
#include "logging_client.h"

void reply_msg_received(reply_data_t *reply_data)
{
    client_event_private_message_received(reply_data->arg1.user_uuid, reply_data->arg2.message_body);
}
