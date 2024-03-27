/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_error_unknow_channel
*/

#include "myteams_client.h"
#include "logging_client.h"

void reply_error_unknow_channel(reply_data_t *reply_data)
{
    client_error_unknown_channel(reply_data->arg1.channel_uuid);
}
