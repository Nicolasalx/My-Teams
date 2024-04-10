/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** unsubscribe
*/

#include "myteams_client.h"
#include "command_list.h"

command_type_t init_unsubscribe(char **array, int nb_arg, cmd_data_t *cmd_data, command_t command)
{
    if (user_is_login() == NOT_LOGGED) {
        return COMMAND_FAILED;
    }
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the unsubscribe\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) != UUID_LENGTH) {
        printf("Bad length of the uuid\n");
        return COMMAND_FAILED;
    }
    cmd_data->type = UNSUBSCRIBE;
    strcpy(cmd_data->arg1.team_uuid, array[1]);
    return COMMAND_SUCCEED;
}
