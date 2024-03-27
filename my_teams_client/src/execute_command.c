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

void parse_line(int *nb_word, char ***array, char *command)
{
    const char *new_str = remove_space_out_quotes(command);
    const char *delimiter = "\"\n";
    *nb_word = count_nb_word(new_str, delimiter);
    int *size_word = count_size_word(new_str, delimiter, *nb_word);
    *array = my_str_to_word(new_str, delimiter, *nb_word, size_word);
}

void execute_command(client_t *client, char *command)
{
    cmd_data_t cmd_data = {0};
    int nb_word = 0;
    char **array = NULL;
    bool is_a_command = false;

    parse_line(&nb_word, &array, command);
    if (nb_word < 1 || nb_word > 4) {
        return;
    }
    for (int i = 0; i < NUMBER_CMD; ++i) {
        if (strcmp(command_list[i].name, array[0]) == 0) {
            command_list[i].cmd_function(array, nb_word, &cmd_data, command_list[i].type);
            is_a_command = true;
        }
    }
    if (is_a_command == false) {
        printf("Command not recognized !\n");
        return;
    }
    if (send(client->fd, &cmd_data, sizeof(cmd_data_t), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}
