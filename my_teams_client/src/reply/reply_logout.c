/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_logout
*/

#include "myteams_client.h"
#include "logging_client.h"

void reply_logout(reply_data_t *reply_data)
{
    client_event_logged_out(reply_data->arg1.user_uuid, reply_data->arg2.user_name);
}

