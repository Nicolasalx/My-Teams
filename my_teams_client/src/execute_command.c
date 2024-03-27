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
    command_type_e command_type = NO_COMMAND;

    parse_line(&nb_word, &array, command);
    if (nb_word < 1 || nb_word > 4) {
        return;
    }
    for (int i = 0; i < NUMBER_CMD; ++i) {
        if (strcmp(command_list[i].name, array[0]) == 0) {
            command_type = command_list[i].cmd_function(array, nb_word, &cmd_data, command_list[i].type);
            is_a_command = true;
        }
    }
    if (is_a_command == false || command_type == COMMAND_FAILED) {
        printf("Command not recognized !\n");
        return;
    }

    printf("\n\nIN ARG 1:\n");
    printf("CHANNEL NAME: %s\n", cmd_data.arg1.channel_name);
    printf("COMMENT BODY: %s\n", cmd_data.arg1.comment_body);
    printf("TEAM NAME: %s\n", cmd_data.arg1.team_name);
    printf("TEAM UUID: %s\n", cmd_data.arg1.team_uuid);
    printf("THREAD TITLE: %s\n", cmd_data.arg1.thread_title);
    printf("USER NAME: %s\n", cmd_data.arg1.user_name);
    printf("USER UUID: %s\n", cmd_data.arg1.user_uuid);

    printf("\nIN ARG 2:\n");
    printf("CHANNEL DESRIPTION: %s\n", cmd_data.arg2.channel_description);
    printf("CHANNEL UUID: %s\n", cmd_data.arg2.channel_uuid);
    printf("MESSAGE BODY: %s\n", cmd_data.arg2.message_body);
    printf("TEAM DESCRIPTION; %s\n", cmd_data.arg2.team_description);
    printf("THREAD MESSAGE: %s\n", cmd_data.arg2.thread_message);

    printf("\nIN ARG 3:\n");
    printf("THREAD UUID: %s\n", cmd_data.arg3.thread_uuid);

    printf("\nONLY IN USE AND SUBSCRIBED\n");
    printf("NB ARG: %ld\n", cmd_data.arg4.nb_arg);


    if (send(client->fd, &cmd_data, sizeof(cmd_data_t), 0) == -1) {
        exit_client(84, RED("Fail to send message to server.\n"));
    }
}
