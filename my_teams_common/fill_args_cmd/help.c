/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** help
*/

#include "myteams_client.h"
#include "command_list.h"

void init_help(char **, int nb_arg, cmd_data_t *cmd_data, command_e command)
{
    if (nb_arg - 1 != command_list[command].nb_arg) {
        printf("Invalid arg in the help\n");
        return;
    }
    cmd_data->type = HELP;
    const char *message_help =
        "HELP\n" \
        "The different commands are:\n";
    printf(message_help);
}
