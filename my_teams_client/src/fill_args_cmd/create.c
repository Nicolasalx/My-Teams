/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** create
*/

#include "myteams_client.h"
#include "command_list.h"

static command_type_t create_new_team(char **array,
    int nb_arg, cmd_data_t *cmd_data)
{
    if (nb_arg != 3) {
        printf("Invalid number of arguments create (new team)\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) > MAX_NAME_LENGTH ||
        strlen(array[2]) > MAX_DESCRIPTION_LENGTH) {
        printf("Invalid number of character in the team name or desc\n");
        return COMMAND_FAILED;
    }
    strcpy(cmd_data->arg1.team_name, array[1]);
    strcpy(cmd_data->arg2.team_description, array[2]);
    return COMMAND_SUCCEED;
}

static command_type_t create_new_channel(char **array,
    int nb_arg, cmd_data_t *cmd_data)
{
    if (nb_arg != 3) {
        printf("Invalid number of arguments create (new team)\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) > MAX_NAME_LENGTH ||
        strlen(array[2]) > MAX_DESCRIPTION_LENGTH) {
        printf("Invalid number of character in the channel name or desc\n");
        return COMMAND_FAILED;
    }
    strcpy(cmd_data->arg1.channel_name, array[1]);
    strcpy(cmd_data->arg2.channel_description, array[2]);
    return COMMAND_SUCCEED;
}

static command_type_t create_new_thread(char **array,
    int nb_arg, cmd_data_t *cmd_data)
{
    if (nb_arg != 3) {
        printf("Invalid number of arguments create (new team)\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) > MAX_NAME_LENGTH ||
        strlen(array[2]) > MAX_BODY_LENGTH) {
        printf("Invalid number of character in the thread title or message\n");
        return COMMAND_FAILED;
    }
    strcpy(cmd_data->arg1.thread_title, array[1]);
    strcpy(cmd_data->arg2.thread_message, array[2]);
    return COMMAND_SUCCEED;
}

static command_type_t create_new_reply(char **array,
    int nb_arg, cmd_data_t *cmd_data)
{
    if (nb_arg != 2) {
        printf("Invalid number of arguments create (new team)\n");
        return COMMAND_FAILED;
    }
    if (strlen(array[1]) > MAX_BODY_LENGTH) {
        printf("Invalid number of character in the thread title or message\n");
        return COMMAND_FAILED;
    }
    strcpy(cmd_data->arg1.comment_body, array[1]);
    return COMMAND_SUCCEED;
}

command_type_t init_create(char **array, int nb_arg,
    cmd_data_t *cmd_data, command_t)
{
    if (user_is_login() == NOT_LOGGED || !(nb_arg >= 1 && nb_arg <= 3)) {
        printf("Invalid number of arguments in the command\n");
        return COMMAND_FAILED;
    }
    cmd_data->type = CREATE;
    switch (context) {
        case NO_CONTEXT:
            return create_new_team(array, nb_arg, cmd_data);
            break;
        case IN_TEAM:
            return create_new_channel(array, nb_arg, cmd_data);
            break;
        case IN_CHANNEL:
            return create_new_thread(array, nb_arg, cmd_data);
            break;
        case IN_THREAD:
            return create_new_reply(array, nb_arg, cmd_data);
            break;
    }
    return COMMAND_SUCCEED;
}
