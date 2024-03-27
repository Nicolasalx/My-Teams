/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"
#include "command_list.h"

char *remove_space_out_quotes(const char *string)
{
    bool is_in_quote = false;
    size_t index = 0;
    char *result = NULL;

    result = malloc(sizeof(char) * (strlen(string)) + 1);
    if (result == NULL) {
        return NULL;
    }
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == '\"') {
            is_in_quote = !is_in_quote;
        }
        if (!is_in_quote && string[i] == ' ') {
            continue;
        } else {
            result[index] = string[i];
            ++index;
        }
    }
    return result;
}

void assign_elem_command(cmd_data_t *cmd_data, int nb_word, char **array, command_list_t command_list)
{
    if (nb_word != command_list.nb_arg) {
        // Error the nb of arguments expected are not the arguments got
        return;
    }

    cmd_data->type = command_list.name;
    cmd_data->arg1. = array[1];
}

void init_help()
{
    
}

void init_login()
{

}

void init_

void execute_command(client_t *client, char *command)
{
    cmd_data_t cmd_data = {0};
    const char *new_str = remove_space_out_quotes(command);
    const char *delimiter = "\"\n";
    int nb_word = count_nb_word(new_str, delimiter);
    int *size_word = count_size_word(new_str, delimiter, nb_word);
    char **array = my_str_to_word(new_str, delimiter, nb_word, size_word);

    if (nb_word < 1 || nb_word > 4) {
        // Error command
        return;
    }

    for (int i = 0; i < size_cmd_list; ++i) {
        if (strcmp(command_list[i].name, array[0]) == 0) {
            assign_elem_command(&cmd_data, nb_word, command_list[i]);
        }
    }

    if (send(client->fd, &cmd_data, sizeof(cmd_data_t), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}
