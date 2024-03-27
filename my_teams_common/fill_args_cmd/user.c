/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** user
*/

#include "myteams_client.h"
#include "command_list.h"

command_type_e init_user(char **array, int nb_arg, cmd_data_t *cmd_data, command_e command)
{
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the user\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) != UUID_LENGTH) {
        printf("Bad length of the uuid\n");
        return COMMAND_FAILED;
    }
    strcpy(cmd_data->arg1.user_uuid, array[1]);
    cmd_data->type = USER;
    return COMMAND_SUCCEED;
}
