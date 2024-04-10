/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** messages
*/

#include "myteams_client.h"
#include "command_list.h"

command_type_t init_messages(char **array, int nb_arg,
    cmd_data_t *cmd_data, command_t command)
{
    if (user_is_login() == NOT_LOGGED) {
        return COMMAND_FAILED;
    }
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the messages\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) != UUID_LENGTH) {
        printf("Bad length of the uuid\n");
        return COMMAND_FAILED;
    }
    cmd_data->type = MESSAGES;
    strcpy(cmd_data->arg1.user_uuid, array[1]);
    return COMMAND_SUCCEED;
}
