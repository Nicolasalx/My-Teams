/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** users
*/

#include "myteams_client.h"
#include "command_list.h"

command_type_t init_users(char **, int nb_arg,
    cmd_data_t *cmd_data, command_t command)
{
    if (user_is_login() == NOT_LOGGED) {
        return COMMAND_FAILED;
    }
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the users\n");
        return COMMAND_FAILED;
    }
    cmd_data->type = USERS;
    return COMMAND_SUCCEED;
}
