/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** command_need_logged_in
*/

#include "myteams_server.h"

bool require_logged_in(char *command)
{
    for (size_t i = 0; command_list[i].str != NULL; ++i) {
        if (strcmp(command, command_list[i].str) == 0) {
            return command_list[i].need_logged_in;
        }
    }
    return false;
}
