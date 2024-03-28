/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_subscribed_user_cmd
*/

#include "myteams_client.h"
#include "logging_client.h"

void reply_subscribed_user_cmd(reply_data_t *reply_data)
{
    client_print_users(
        reply_data->arg1.user_uuid,
        reply_data->arg2.user_name,
        reply_data->arg3.user_status
    );
}
