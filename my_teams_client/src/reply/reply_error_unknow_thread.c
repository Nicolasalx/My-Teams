/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_error_unknow_thread
*/

#include "myteams_client.h"

void reply_error_unknow_thread(reply_data_t *reply_data)
{
    CLIENT_ERROR_UNKNOWN_THREAD(reply_data->arg1.thread_uuid);
}
