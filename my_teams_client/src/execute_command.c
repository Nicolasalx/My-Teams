/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-thibaud.cathala
** File description:
** execute_command
*/

#include "myteams_client.h"
#include "command_list.h"

static command_type_e check_nb_arg_with_one(const char *command)
{
    bool has_found_space = false;

    for (size_t i = 0; command[i] != '\0'; ++i) {
        if (command[i] == ' ') {
            has_found_space = true;
        } else if (has_found_space == true) {
            return COMMAND_FAILED;
        }
    }
    return COMMAND_SUCCEED;
}

static command_type_e check_nb_arg(int *nb_word, const char *command)
{
    bool is_in_quotes = false;
    bool has_found_frst_elem = false;

    if (*nb_word < 1 || *nb_word > 4) {
        printf("Command not recognized !\n");
        return COMMAND_FAILED;
    }
    if (*nb_word == 1 && check_nb_arg_with_one(command) == COMMAND_FAILED) {
        printf("Command not recognized !\n");
        return COMMAND_FAILED;
    }
    for (size_t i = 0; command[i] != '\0'; ++i) {
        if (command[i] == '\"') {
            is_in_quotes = !is_in_quotes;
            has_found_frst_elem = true;
        } else if (!is_in_quotes && has_found_frst_elem && !is_in_str(command[i], "\" \t\n")) {
            printf("Command not recognized !\n");
            return COMMAND_FAILED;
        }
    }
    return COMMAND_SUCCEED;
}

static int count_nb_word_quotes(const char *str)
{
    int result = 0;
    bool is_in_quote = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\"') {
            is_in_quote = !is_in_quote;
            ++result;
        }
    }
    if (result % 2 != 0) {
        return -1;
    }
    return result / 2;
}

static void count_size_word_opt(bool *is_in_quotes, int **size_word, int *index, int *count_size_word)
{
    if (*is_in_quotes) {
        (*size_word)[*index] = *count_size_word;
        *is_in_quotes = false;
        ++*index;
        *count_size_word = 0;
    } else {
        *is_in_quotes = true;
    }
}

static int *count_size_word_quotes(int nb_word, char *delimiter, const char *str)
{
    int *size_word = malloc_array(nb_word);
    int count_size_word = 0;
    int index = 0;
    bool is_in_quotes = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter)) {
            count_size_word_opt(&is_in_quotes, &size_word, &index, &count_size_word);
        } else if (is_in_quotes) {
            ++count_size_word;
        }
    }
    return size_word;
}

static void my_str_to_word_opt(bool *is_in_quotes, int *i_index, int *j_index)
{
    if (*is_in_quotes) {
        ++*i_index;
        *j_index = 0;
        *is_in_quotes = false;
    } else {
        *is_in_quotes = true;
    }
}

static char **my_str_to_word_quotes(int nb_word, int *size_word,
    char *delimiter, const char *str)
{
    char **word = malloc_adv_board(nb_word, size_word);
    int i_index = 0;
    int j_index = 0;
    bool is_in_quotes = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter)) {
            my_str_to_word_opt(&is_in_quotes, &i_index, &j_index);
        } else if (is_in_quotes) {
            word[i_index][j_index] = str[i];
            ++j_index;
        }
    }
    return word;
}

static char *get_first_command(const char *str, const char *delimiter)
{
    size_t idx = 0;
    char *result;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter)) {
            break;
        }
        ++idx;
    }
    result = my_malloc(sizeof(char) * (idx + 1));
    memcpy(result, str, idx);
    return result;
}

static command_type_e parse_line(int *nb_word, char ***array, char *command)
{
    int *size_word_quotes = NULL;
    char **board;
    char *frst_command = get_first_command(command, "\" \n\t");

    *nb_word = count_nb_word_quotes(command);
    if (*nb_word == -1) {
        printf("Command not recognized !\n");
        return COMMAND_FAILED;
    }
    size_word_quotes = count_size_word_quotes(*nb_word, "\"\n", command);
    *array = my_str_to_word_quotes(*nb_word, size_word_quotes, "\"\n", command);
    ++*nb_word;
    board = my_malloc(sizeof(char *) * (*nb_word + 1));
    board[0] = frst_command;
    for (int i = 0; i < *nb_word - 1; i++) {
        board[i + 1] = (*array)[i];
    }
    board[*nb_word] = NULL;
    *array = board;
    return check_nb_arg(nb_word, command);
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

static void send_cmd(client_t *client, bool is_a_command,
    command_type_e command_type, cmd_data_t *cmd_data)
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
            command_type = command_list[i].cmd_function(array, nb_word,
                &cmd_data, command_list[i].type);
            is_a_command = true;
        }
    }
    send_cmd(client, is_a_command, command_type, &cmd_data);
}
