/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** reply_string
*/

#include "myteams_client.h"

void reply_string(reply_data_t *reply_data)
{
    puts((char *) &reply_data->arg1);
}
