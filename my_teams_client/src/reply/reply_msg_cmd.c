/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_msg_cmd
*/

#include "myteams_client.h"

void reply_msg_cmd(reply_data_t *reply_data)
{
    CLIENT_PRIVATE_MESSAGE_PRINT_MESSAGES(
        reply_data->arg1.sender_uuid,
        reply_data->arg2.message_timestamp,
        reply_data->arg3.message_body
    );
}
