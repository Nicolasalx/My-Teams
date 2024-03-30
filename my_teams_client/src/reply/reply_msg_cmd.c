/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_msg_cmd
*/

#include "myteams_client.h"

void reply_msg_cmd(reply_data_t *reply_data)
{
    client_private_message_print_messages(
        reply_data->arg1.sender_uuid,
        reply_data->arg2.message_timestamp,
        reply_data->arg3.message_body
    );
}
