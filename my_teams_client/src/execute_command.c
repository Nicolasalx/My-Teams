/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"
#include "command_list.h"

static void remove_space_opt(char c, bool is_in_quote, char *result, size_t *index)
{
    if (!is_in_quote && c == ' ') {
        return;
    } else {
        result[*index] = c;
        ++*index;
    }
}

static char *remove_space_out_quotes(const char *string)
{
    bool is_in_quote = false;
    size_t index = 0;
    char *result = NULL;
    size_t nb_quotes = 0;

    result = my_calloc(sizeof(char) * (strlen(string)) + 1);
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == '\"') {
            is_in_quote = !is_in_quote;
            ++nb_quotes;
        }
        remove_space_opt(string[i], is_in_quote, result, &index);
    }
    if (nb_quotes % 2 != 0) {
        return NULL;
    }
    return result;
}

static command_type_e parse_line(int *nb_word, char ***array, char *command)
{
    const char *new_str = remove_space_out_quotes(command);
    const char *delimiter = "\"\n";
    int *size_word = NULL;

    if (new_str == NULL) {
        printf("Command not recognized !\n");
        return COMMAND_FAILED;
    }
    *nb_word = count_nb_word(new_str, delimiter);
    size_word = count_size_word(new_str, delimiter, *nb_word);
    *array = my_str_to_word(new_str, delimiter, *nb_word, size_word);
    if (*nb_word < 1 || *nb_word > 4) {
        printf("Command not recognized !\n");
        return COMMAND_FAILED;
    }
    return COMMAND_SUCCEED;
}

static command_type_e check_error_cmd(bool is_a_command, command_type_e command_type)
{
    if (is_a_command == false) {
        printf("Command not recognized !\n");
        return COMMAND_FAILED;
    }
    if (command_type == COMMAND_FAILED) {
        return COMMAND_FAILED;
    }
    return COMMAND_SUCCEED;
}

static void send_cmd(client_t *client, bool is_a_command, command_type_e command_type, cmd_data_t *cmd_data)
{
    if (check_error_cmd(is_a_command, command_type) == COMMAND_FAILED) {
        return;
    }
    if (send(client->fd, cmd_data, sizeof(cmd_data_t), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}

void execute_command(client_t *client, char *command)
{
    cmd_data_t cmd_data = {0};
    int nb_word = 0;
    char **array = NULL;
    bool is_a_command = false;
    command_type_e command_type = NO_COMMAND;

    if (parse_line(&nb_word, &array, command) == COMMAND_FAILED) {
        return;
    }
    for (int i = 0; i < NUMBER_CMD; ++i) {
        if (strcmp(command_list[i].name, array[0]) == 0) {
            command_type = command_list[i].cmd_function(array, nb_word, &cmd_data, command_list[i].type);
            is_a_command = true;
        }
    }
    send_cmd(client, is_a_command, command_type, &cmd_data);
}
