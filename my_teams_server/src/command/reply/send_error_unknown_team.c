/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send_error_unknown_team
*/

#include "myteams_server.h"

void send_error_unknown_team(int fd, const char *team_uuid)
{
    reply_data_t reply_data = {0};

    reply_data.type = ERROR_UNKNOWN_TEAM;
    memcpy(reply_data.arg1.team_uuid, team_uuid, UUID_LENGTH);
    send_reply_to_client(fd, &reply_data);
}
