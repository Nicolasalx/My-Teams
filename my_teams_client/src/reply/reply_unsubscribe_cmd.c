/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_unsubscribe_cmd
*/

#include "myteams_client.h"

void reply_unsubscribe_cmd(reply_data_t *reply_data)
{
    client_print_unsubscribed(
        reply_data->arg1.user_uuid,
        reply_data->arg2.team_uuid
    );
}
