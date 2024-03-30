/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_unknow_user
*/

#include "myteams_client.h"

void reply_unknow_user(reply_data_t *reply_data)
{
    CLIENT_ERROR_UNKNOWN_USER(reply_data->arg1.user_uuid);
}
