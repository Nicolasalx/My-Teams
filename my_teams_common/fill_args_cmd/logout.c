/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** logout
*/

#include "myteams_client.h"
#include "command_list.h"

void init_logout(char **, int nb_arg, cmd_data_t *cmd_data, command_e command)
{
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the logout\n");
        return;
    }
    cmd_data->type = LOGOUT;
}
