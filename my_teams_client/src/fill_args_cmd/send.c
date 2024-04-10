/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** send
*/

#include "myteams_client.h"
#include "command_list.h"

command_type_t init_send(char **array, int nb_arg,
    cmd_data_t *cmd_data, command_t command)
{
    if (user_is_login() == NOT_LOGGED) {
        return COMMAND_FAILED;
    }
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the send\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) != UUID_LENGTH ||
        strlen(array[2]) > MAX_BODY_LENGTH) {
        printf("Bad length of the uuid or the message body\n");
        return COMMAND_FAILED;
    }
    cmd_data->type = SEND;
    strcpy(cmd_data->arg1.user_uuid, array[1]);
    strcpy(cmd_data->arg2.message_body, array[2]);
    return COMMAND_SUCCEED;
}
