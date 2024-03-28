/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_create_channel_cmd
*/

#include "myteams_client.h"
#include "logging_client.h"

void reply_create_channel_cmd(reply_data_t *reply_data)
{
    client_print_channel_created(
        reply_data->arg1.channel_uuid,
        reply_data->arg2.channel_name,
        reply_data->arg3.channel_description);
}
