/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"
#include "command_list.h"

static command_type_t check_nb_arg_with_one(const char *command)
{
    bool has_found_space = false;

    for (size_t i = 0; command[i] != '\0'; ++i) {
        if (command[i] == ' ') {
            has_found_space = true;
            continue;
        }
        if (has_found_space == true) {
            return COMMAND_FAILED;
        }
    }
    return COMMAND_SUCCEED;
}

static command_type_t check_nb_arg_opt(const int *nb_word, const char *command)
{
    if (*nb_word < 1 || *nb_word > 4) {
        printf("Command not recognized in check ng arg (1)!\n");
        return COMMAND_FAILED;
    }
    if (*nb_word == 1 && check_nb_arg_with_one(command) == COMMAND_FAILED) {
        printf("Command not recognized in check nb arg (2)!\n");
        return COMMAND_FAILED;
    }
    return COMMAND_SUCCEED;
}

static command_type_t check_nb_arg(const int *nb_word, const char *command)
{
    bool is_in_quotes = false;
    bool has_found_frst_elem = false;

    if (check_nb_arg_opt(nb_word, command) == COMMAND_FAILED) {
        return COMMAND_FAILED;
    }
    for (size_t i = 0; command[i] != '\0'; ++i) {
        if (command[i] == '\"') {
            is_in_quotes = !is_in_quotes;
            has_found_frst_elem = true;
            continue;
        }
        if (!is_in_quotes && has_found_frst_elem
            && !is_in_str(command[i], "\" \t\n")) {
            printf("Command not recognized in check nb arg (3)!\n");
            return COMMAND_FAILED;
        }
    }
    return COMMAND_SUCCEED;
}

static char *get_first_command(const char *str, const char *delimiter)
{
    size_t idx = 0;
    char *result = NULL;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter)) {
            break;
        }
        ++idx;
    }
    result = my_calloc(sizeof(char) * (idx + 1));
    memcpy(result, str, idx);
    return result;
}

command_type_t parse_line(int *nb_word, char ***array, char *command)
{
    int *size_word_quotes = NULL;
    char **board = NULL;
    char *frst_command = get_first_command(command, "\" \n\t");

    *nb_word = count_nb_word_quotes(command);
    if (*nb_word == -1) {
        printf("Command not recognized in parse line !\n");
        return COMMAND_FAILED;
    }
    size_word_quotes = count_size_word_quotes(*nb_word, "\"\n", command);
    *array = my_str_to_word_quotes(*nb_word,
        size_word_quotes, "\"\n", command);
    ++*nb_word;
    board = my_calloc(sizeof(char *) * (*nb_word + 1));
    board[0] = frst_command;
    for (int i = 0; i < *nb_word - 1; i++)
        board[i + 1] = (*array)[i];
    board[*nb_word] = NULL;
    *array = board;
    return check_nb_arg(nb_word, command);
}

command_type_t check_error_cmd(bool is_a_command,
    command_type_t command_type)
{
    if (is_a_command == false) {
        printf("Command not recognized in check error cmd!\n");
        return COMMAND_FAILED;
    }
    if (command_type == COMMAND_FAILED) {
        return COMMAND_FAILED;
    }
    return COMMAND_SUCCEED;
}

void send_cmd(client_t *client, bool is_a_command,
    command_type_t command_type, cmd_data_t *cmd_data)
{
    if (check_error_cmd(is_a_command, command_type) == COMMAND_FAILED) {
        return;
    }
    send_cmd_to_server(client, cmd_data);
}

void execute_command(client_t *client, char *command)
{
    cmd_data_t cmd_data = {0};
    int nb_word = 0;
    char **array = NULL;
    bool is_a_command = false;
    command_type_t command_type = NO_COMMAND;

    if (parse_line(&nb_word, &array, command) == COMMAND_FAILED) {
        return;
    }
    for (int i = 0; i < NUMBER_CMD; ++i) {
        if (strcmp(command_list[i].name, array[0]) == 0) {
            command_type = command_list[i].cmd_function(array, nb_word,
                &cmd_data, command_list[i].type);
            is_a_command = true;
        }
    }
    send_cmd(client, is_a_command, command_type, &cmd_data);
}
